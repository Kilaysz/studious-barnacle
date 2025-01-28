#include <stdio.h>
#include <stdlib.h>

int IP[1000000][4], special_group[100000];
int total_file = 0;
int prefix[33] = {0}; // Assuming prefix lengths can range from 0 to 32
int i = 0, prefix_length[100000], d, group[256] = {0}; // Initialize group array

struct prefix {
    unsigned ip;
    unsigned char len;
    struct prefix* next;
};

struct prefix* groups[256] = {0}; // Initialize an array of linked lists for each group

// Comparison function for qsort to compare IP addresses based on all octets
int compareIP(const void *a, const void *b) {
    const int (*ipA)[4] = a;
    const int (*ipB)[4] = b;

    // Compare based on the first octet
    int result = (*ipA)[0] - (*ipB)[0];

    // If the first octet is the same, compare the remaining octets
    if (result == 0) {
        for (int i = 1; i < 4; i++) {
            result = (*ipA)[i] - (*ipB)[i];
            if (result != 0) {
                break; // Stop comparing if a difference is found
            }
        }
    }

    return result;
}

// Function to insert a node into a linked list in sorted order
void insert_sorted(struct prefix** head, unsigned ip, unsigned char len) {
    struct prefix* new_node = (struct prefix*)malloc(sizeof(struct prefix));
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

// Function to print the linked list
void print_list(struct prefix* head) {
    while (head != NULL) {
        printf("%u.%u.%u.%u/%d\n", (head->ip >> 24) & 0xFF, (head->ip >> 16) & 0xFF, (head->ip >> 8) & 0xFF, head->ip & 0xFF, head->len);
        head = head->next;
    }
}

void segment(int d) {
    if (prefix_length[i] >= d) {
        unsigned int group_id = 0;
        // Calculate group ID based on the first 'd' bits
        for (int j = 0; j < d; j++) {
            group_id = (group_id << 1) | ((IP[i][j / 8] >> (7 - j % 8)) & 1);
        }

        group[group_id] += 1;

        // Insert the current IP into the linked list for the corresponding group
        insert_sorted(&groups[group_id], (IP[i][0] << 24) | (IP[i][1] << 16) | (IP[i][2] << 8) | IP[i][3], prefix_length[i]);
    } else {
        special_group[i] += 1;
    }
}

void length_distribution(int length) {
    prefix[length] += 1;
}

void input(FILE *file) {
    while (fscanf(file, "%u.%u.%u.%u/%d", &IP[i][0], &IP[i][1], &IP[i][2], &IP[i][3], &prefix_length[i]) == 5) {
        length_distribution(prefix_length[i]);
        segment(d);
        total_file += 1;
        i++;
    }

    printf("The total number of prefixes in the input file is : %d.\n", total_file);
    for (int j = 0; j <= (1 << d) - 1; j++) {
        printf("The number of prefixes in group %d = %d\n", j, group[j]);
    }
}

void insert_prefix(FILE* insert_file) {
    unsigned int ip;
    unsigned char len;

    while (fscanf(insert_file, "%u.%u.%u.%u/%hhu", &IP[i][0], &IP[i][1], &IP[i][2], &IP[i][3], (unsigned char*)&prefix_length[i]) == 5) {
        length_distribution(prefix_length[i]);
        total_file += 1;
        i++;

        if (prefix_length[i - 1] >= d) {
            unsigned int group_id = 0;
            // Calculate group ID based on the first 'd' bits
            for (int j = 0; j < d; j++) {
                group_id = (group_id << 1) | ((IP[i - 1][j / 8] >> (7 - j % 8)) & 1);
            }

            group[group_id] += 1;

            // Insert the current IP into the linked list for the corresponding group
            insert_sorted(&groups[group_id], (IP[i - 1][0] << 24) | (IP[i - 1][1] << 16) | (IP[i - 1][2] << 8) | IP[i - 1][3], prefix_length[i - 1]);
        } else {
            special_group[i - 1] += 1;
        }
    }
}

void delete_prefix(struct prefix** head, unsigned ip, int d) {
    unsigned int group_id = 0;
    for (int j = 0; j < d; j++) {
        group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
    }

    struct prefix* current = *head;
    struct prefix* prev = NULL;

    while (current != NULL && current->ip != ip) {
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

void delete_prefix_from_groups(unsigned int ip, int d) {
    unsigned int group_id = 0;
    for (int j = 0; j < d; j++) {
        group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
    }

    delete_prefix(&groups[group_id], ip, d);
}

void insert_prefix(FILE* insert_file) {
    unsigned int ip1, ip2, ip3, ip4;
    unsigned char len;

    while (fscanf(insert_file, "%u.%u.%u.%u/%hhu", &ip1, &ip2, &ip3, &ip4, (unsigned char*)&len) == 5) {
        length_distribution(len);
        total_file += 1;

        // Insert the current IP into the linked list for the corresponding group
        if (len >= d) {
            unsigned int ip = (ip1 << 24) | (ip2 << 16) | (ip3 << 8) | ip4;
            segment(ip, len);
            unsigned int group_id = 0;
            for (int j = 0; j < d; j++) {
                group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
            }
            group[group_id] += 1;
            insert_sorted(&groups[group_id], ip, len);
        } else {
            special_group[i - 1] += 1;
        }
    }
}

void search(FILE* trace_file) {
    unsigned int ip1, ip2, ip3, ip4;
    unsigned char len;

    while (fscanf(trace_file, "%u.%u.%u.%u/%hhu", &ip1, &ip2, &ip3, &ip4, &len) == 5) {
        // Combine the octets into a single IP address
        unsigned int ip = (ip1 << 24) | (ip2 << 16) | (ip3 << 8) | ip4;

        // Search for the prefix in the appropriate linked list
        unsigned int group_id = 0;
        // Calculate group ID based on the first 'd' bits
        for (int j = 0; j < d; j++) {
            group_id = (group_id << 1) | ((ip >> (31 - j)) & 1);
        }

        // Create the search key in the same way as insert_prefix
        unsigned int search_key = (ip << 16) | len;  // Fix format specifier here

        printf("Searching for prefix %u.%u.%u.%u/%hhu in group %u...\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF, len, group_id);

        int result = search_prefix(groups[group_id], search_key, len);

        if (result) {
            printf("Prefix %u.%u.%u.%u/%hhu found.\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF, len);
        } else {
            printf("Prefix %u.%u.%u.%u/%hhu not found.\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF, len);
        }
    }
}

int main(int argc, char *argv[]) {
    d = atoi(argv[5]);
    FILE *file = fopen(argv[1], "r");
    FILE *insert_file = fopen(argv[2], "r");
    FILE *delete_file = fopen(argv[3], "r");
    FILE *trace_file = fopen(argv[4], "r");

    if (file == NULL || insert_file == NULL || delete_file == NULL || trace_file == NULL) {
        perror("Error opening file");
        return 1;  // Return an error code
    }

    input(file);
    insert_prefix(insert_file);

    // Assuming delete_file contains IP addresses to delete
    unsigned int delete_ip;
    unsigned char delete_len;
    while (fscanf(delete_file, "%u.%u.%u.%u/%hhu", &delete_ip, &delete_ip, &delete_ip, &delete_ip, (unsigned char*)&delete_len) == 5) {
        delete_prefix_from_groups(delete_ip, d);
    }

    search(trace_file);

    fclose(file);
    fclose(insert_file);
    fclose(delete_file);
    fclose(trace_file);
    return 0;
}