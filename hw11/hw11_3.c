#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h> 

typedef struct Prefix {
    uint32_t ip;
    uint8_t length;
    struct Prefix *next;
} Prefix;

Prefix *input(const char *filename, int *totalPrefixes);
void lengthDistribution(Prefix *prefixArray);
void segment(Prefix **groups, Prefix *prefixArray, int d);
void printSpecialGroup(Prefix *specialGroup);
void prefixInsert(Prefix **group, Prefix *newPrefix);
void prefixDelete(Prefix **group, uint32_t ip);
int search(Prefix **groups, int d, uint32_t searchIP);

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <routing_table_file> <inserted_prefixes_file> <deleted_prefixes_file> <trace_file> <d>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *routingTableFile = argv[1];
    const char *insertedPrefixesFile = argv[2];
    const char *deletedPrefixesFile = argv[3];
    const char *traceFile = argv[4];
    int d = atoi(argv[5]);

    int totalPrefixes;
    Prefix *prefixArray = input(routingTableFile, &totalPrefixes);
    printf("The total number of prefixes in the input file is: %d.\n", totalPrefixes);

    lengthDistribution(prefixArray);

    Prefix **groups = (Prefix **)malloc((1 << d) * sizeof(Prefix *));
    if (groups == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < (1 << d); i++) {
        groups[i] = NULL;
    }

    segment(groups, prefixArray, d);

    for (int i = 0; i < (1 << d); i++) {
    int count = 0;
    Prefix *current = groups[i];
    while (current != NULL) {
        count++;
        current = current->next;
    }
    if (count > 0) {
        printf("Number of prefixes in group %d: %d\n", i, count);
    }
}

    printSpecialGroup(groups[(1 << d) - 1]);

    Prefix *traceArray = input(traceFile, &totalPrefixes);
    for (int i = 0; i < totalPrefixes; ++i) {
        int result = search(groups, d, traceArray[i].ip);
        printf(result ? "successful\n" : "failed\n");
    }

    free(prefixArray);

    return 0;
}

Prefix *input(const char *filename, int *totalPrefixes) {
    FILE *file;
    char line[100];
    Prefix *prefixArray = NULL;
    Prefix *currentPrefix = NULL;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *totalPrefixes = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
    line[strcspn(line, "\n")] = '\0';

    Prefix *newPrefix = (Prefix *)malloc(sizeof(Prefix));
    if (newPrefix == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    uint32_t shiftedIp = newPrefix->ip >> 8;
    if (sscanf(line, "%hhu.%hhu.%hhu.%hhu/%hhu",
               (unsigned char *)&(newPrefix->ip),
               (unsigned char *)&shiftedIp,
               (unsigned char *)&shiftedIp,
               (unsigned char *)&shiftedIp,
               &(newPrefix->length)) != 5) {
        free(newPrefix);  // Free memory in case of error
        continue;
    }

    newPrefix->next = NULL;

    if (currentPrefix == NULL) {
        prefixArray = newPrefix;
        currentPrefix = newPrefix;
    } else {
        currentPrefix->next = newPrefix;
        currentPrefix = newPrefix;
    }

    (*totalPrefixes)++;
}

    fclose(file);
    return prefixArray;
}

void segment(Prefix **groups, Prefix *prefixArray, int d) {
    Prefix *current = prefixArray;
    while (current != NULL) {
        int groupIndex;

        if (current->length < d) {
            // Prefix of length < d goes to a special group
            groupIndex = (1 << d);  // Special group index
        } else {
            groupIndex = (current->ip >> (32 - d));
        }

        // Exclude the special group from counting
        if (groupIndex != (1 << d))
            prefixInsert(&groups[groupIndex], current);

        current = current->next;
    }
}


void lengthDistribution(Prefix *prefixArray) {
    int lengthCount[33] = {0};

    Prefix *current = prefixArray;
    while (current != NULL) {
        lengthCount[current->length]++;
        current = current->next;
    }

    for (int i = 0; i < 32; i++) {
        printf("The number of prefixes in group %d = %d\n", i, lengthCount[i]);
    }
}

void printSpecialGroup(Prefix *specialGroup) {
    if (specialGroup == NULL) {
        return;  // No special group, so skip printing
    }

    printf("--------special group--------\n");
    Prefix *current = specialGroup;
    while (current != NULL) {
        printf("%hhu.%hhu.%hhu.%hhu\n",
               (unsigned char)current->ip,
               (unsigned char)(current->ip >> 8),
               (unsigned char)(current->ip >> 16),
               (unsigned char)(current->ip >> 24));
        current = current->next;
    }
    printf("-----------------------------\n");
}

void prefixInsert(Prefix **group, Prefix *newPrefix) {
    Prefix *current = *group;
    Prefix *prev = NULL;

    while (current != NULL && current->ip < newPrefix->ip) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newPrefix->next = *group;
        *group = newPrefix;
    } else {
        prev->next = newPrefix;
        newPrefix->next = current;
    }
}

void prefixDelete(Prefix **group, uint32_t ip) {
    Prefix *current = *group;
    Prefix *prev = NULL;

    while (current != NULL && current->ip != ip) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *group = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

int search(Prefix **groups, int d, uint32_t searchIP) {
    int groupIndex = (searchIP >> (32 - d));
    Prefix *current = groups[groupIndex];
    while (current != NULL) {
        if ((current->ip & ((uint32_t)0xFFFFFFFF << (32 - d))) == (searchIP & ((uint32_t)0xFFFFFFFF << (32 - d)))) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}