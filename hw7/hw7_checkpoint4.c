#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool choose[23];
int total_file = 0, file_name, namearr[24], closestSum = INT_MAX;
int file_size, size[23], total_size, k, m;

void solve(int idx, int sum, int remaining) {
    if (idx > 21) {
        if (remaining == 0 && abs(m - sum) < abs(m - closestSum)) {
            closestSum = sum;
            for (int i = 0; i < 21; i++) {
                choose[i] = choose[i];
            }
        }
        return;
    }
    choose[idx - 1] = true; // delete this file
    solve(idx + 1, sum + size[idx], remaining - 1);
    choose[idx - 1] = false;
    solve(idx + 1, sum, remaining); // don't delete this file
}

int main() {
    int opt;
    while (1) {
        printf("Options: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Please input file name and file size: ");
            scanf("%d %d", &file_name, &file_size);
            if (total_file < 20) {
                total_file += 1;
                namearr[total_file] = file_name;
                size[total_file] = file_size;
            } else {
                total_file += 1;
                namearr[total_file] = file_name;
                size[total_file] = file_size;
                printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
                scanf("%d %d", &k, &m);
                closestSum = INT_MAX; // reset closestSum
                solve(1, 0, k);
                for (int i = 0; i < 21; i++) { // delete the file
                    if (choose[i]) {
                        if (i < 20) {
                            printf("%d ", namearr[i + 1]);
                        } else {
                            printf("%d", namearr[i + 1]);
                        }
                        namearr[i + 1] = 0;
                        size[i + 1] = 0;
                    }
                }
                for (int i = 1; i <= 20; i++) { // align the array
                    if (namearr[i] == 0) {
                        namearr[i] = namearr[i + 1];
                        size[i] = size[i + 1];
                        namearr[i + 1] = 0;
                        size[i + 1] = 0;
                    }
                }
                total_file = 21 - k;
                printf("\n");
            }
        } else if (opt == 2) {
            printf("Please input the file name: "); // check whether file name exists
            scanf("%d", &file_name);
            if (total_file == 0) {
                printf("NO\n");
                goto skip;
            }
            bool found = false;
            for (int i = 1; i <= 20; i++) {
                if (file_name == namearr[i]) {
                    printf("YES\n");
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("NO\n");
            }
        skip:;
        } else {
            return 0;
        }
    }
}
