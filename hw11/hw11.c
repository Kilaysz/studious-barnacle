#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for array sizes
#define MAX_PREFIXES 100000
#define MAX_GROUPS 99999999
unsigned long long int begin,end;

unsigned long long int rdtsc_64bits()//64-bit
{
   unsigned long long int x;
   unsigned a, d;

   __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

   return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}


int IP[MAX_PREFIXES][4], specialgroup[MAX_PREFIXES], special_group;
int total_file = 0;
int prefix[33] = {0}; // Assuming prefix lengths can range from 0 to 32
int i = 0, prefix_length[MAX_PREFIXES], d, group[MAX_GROUPS] = {0}; // Initialize group array

struct prefix {
    unsigned int ip; // Changed from unsigned to unsigned int
    int len;         // Changed from unsigned char to int
    struct prefix* next;
};

struct prefix* groups[MAX_GROUPS] = {0}; // Initialize an array of linked lists for each group

// Function to insert a node into a linked list in sorted order
void insert_sorted(struct prefix** head, unsigned int ip, int len) {
    struct prefix* new_node = (struct prefix*)malloc(sizeof(struct prefix));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->ip = ip;
    new_node->len = len;
    new_node->next = NULL;

    struct prefix* current = *head;
    struct prefix* previous = NULL;

    while (current != NULL && (current->ip < ip || (current->ip == ip && current->len < len))) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        new_node->next = previous->next;
        previous->next = new_node;
    }
}

void segment(unsigned int ip, int len) {
    if (len >= d) {
        if (i >= MAX_PREFIXES) {
            fprintf(stderr, "Error: Prefix array index out of bounds\n");
            exit(1);
        }

        unsigned int group_id = 0;
        // Calculate group ID based on the first 'd' bits
        for (int j = 0; j < d; j++) {
            group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
        }

        if (group_id >= MAX_GROUPS) {
            fprintf(stderr, "Error: Group index out of bounds\n");
            exit(1);
        }

        group[group_id] += 1;

        // Insert the current IP into the linked list for the corresponding group
        insert_sorted(&groups[group_id], ip, len);
    } else {
        if (i >= MAX_PREFIXES) {
            fprintf(stderr, "Error: Prefix array index out of bounds\n");
            exit(1);
        }

        special_group += 1;
        specialgroup[i]=ip;
        // put the IP into the special group
    }
}

void length_distribution(int length) {
    if (length >= 0 && length <= 32) {
        prefix[length] += 1;
    } else {
        fprintf(stderr, "Error: Invalid prefix length\n");
        exit(1);
    }
}

void input(FILE* file) {
    while (fscanf(file, "%u.%u.%u.%u/%d", &IP[i][0], &IP[i][1], &IP[i][2], &IP[i][3], &prefix_length[i]) == 5) {
        length_distribution(prefix_length[i]);
        unsigned int ip = (IP[i][0] << 24) | (IP[i][1] << 16) | (IP[i][2] << 8) | IP[i][3];
        segment(ip, prefix_length[i]);
        total_file += 1;
        i++;
    }
}

void insert_prefix(FILE* insert_file) {
    unsigned int ip;
    int len;
    while (fscanf(insert_file, "%u.%u.%u.%u/%d", &IP[i][0], &IP[i][1], &IP[i][2], &IP[i][3], &len) == 5) {
        length_distribution(len);
        unsigned int ip = (IP[i][0] << 24) | (IP[i][1] << 16) | (IP[i][2] << 8) | IP[i][3];
        segment(ip, len);
        total_file += 1;
        i++;
    }
}

void delete_prefix(struct prefix** head, unsigned int ip, int len) {
    struct prefix* current = *head;
    struct prefix* prev = NULL;

    while (current != NULL && (current->ip != ip || current->len != len)) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void delete_prefix_from_groups(unsigned int ip, int len) {
    unsigned int group_id = 0;
    // Calculate group ID based on the first 'd' bits
    for (int j = 0; j < d; j++) {
        group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
    }
    delete_prefix(&groups[group_id], ip, len);
}

// Function to search for a prefix in a linked list
int search_prefix(struct prefix* head, unsigned int key) {
    while (head != NULL) {
        if (head->ip == key) {
            return 1; // Prefix found
        }
        head = head->next;
    }
    return 0; // Prefix not found
}

void search(FILE* trace_file) {
    unsigned int ip1, ip2, ip3, ip4;

    while (fscanf(trace_file, "%u.%u.%u.%u", &ip1, &ip2, &ip3, &ip4) == 4) {
        // Combine the octets into a single IP address
        unsigned int ip = (ip1 << 24) | (ip2 << 16) | (ip3 << 8) | ip4;

        // Search for the prefix in the appropriate linked list
        unsigned int group_id = 0;
        // Calculate group ID based on the first 'd' bits
        for (int j = 0; j < d; j++) {
            group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
        }

        // Create the search key using only the IP address
        int result = search_prefix(groups[group_id], ip);
        /*if (result) {
            printf("Successful\n");
        } else {
            printf("Failed\n");
        } 
        end:*/
    }
}

int main(int argc, char *argv[]) {
    d = atoi(argv[5]);
    FILE *file = fopen(argv[1], "r");
    FILE *insert_file = fopen(argv[2], "r");
    FILE *delete_file = fopen(argv[3], "r");
    FILE *trace_file = fopen(argv[4], "r");

    input(file);
    printf("The total number of prefixes in the input file is: %d.\n", total_file);
    for (int j = 0; j < (1 << d); j++) {
        printf("The number of prefixes in group %d = %d\n", j, group[j]);
    }
    
    insert_prefix(insert_file);
    // Assuming delete_file contains IP addresses to delete
    unsigned int delete_ip;
    int delete_len; // Changed from unsigned char to int
    while (fscanf(delete_file, "%u.%u.%u.%u/%d", &delete_ip, &delete_ip, &delete_ip, &delete_ip, &delete_len) == 5) {
        delete_prefix_from_groups(delete_ip, delete_len);
    }

    search(trace_file);
    fclose(file);
    fclose(insert_file);
    fclose(delete_file);
    fclose(trace_file);
    return 0;
}