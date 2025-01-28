#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool choose[23];
int total_file = 0, file_name, namearr[22], closestSum = INT_MAX;
int file_size, size[25], total_size, k, m, selectedFiles[25];

void solve(int idx, int sum, int remaining) {
    if (idx > 21) {
        if (remaining == 0 && abs(m - sum) < abs(m - closestSum)) {
            closestSum = sum;
            for (int i = 0; i < 21; i++) {
                selectedFiles[i] = choose[i];
            }
        }
        return;
    }
    choose[idx - 1] = true; // delete this file
    solve(idx + 1, sum + size[idx - 1], remaining - 1);
    closestSum = INT_MAX;
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
                for(int index = 1; index<=20; index++){
                    if(namearr[index]==0){
                    namearr[index] = file_name;
                    size[index] = file_size;
                    break;
                    }
                }
            } else {
                total_file += 1;
                namearr[21] = file_name;
                size[21] = file_size;
                printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
                scanf("%d %d", &k, &m);
                closestSum=INT_MAX;
                solve(1, 0, k);
                for (int i = 0; i <= 20; i++){ // delete the file
                    if (selectedFiles[i]) {
                        if(i<20){
                            printf("%d ", namearr[i+1]);
                        } else {
                            printf("%d", namearr[i+1]);
                        }
                        namearr[i+1]=0;
                        size[i+1]=0;
                    }
                }
                for(int i=1; i<=20;i++){ // align the array
                    if(namearr[i]==0){
                        namearr[i+1]=namearr[i];
                        size[i+1]=size[i];
                        namearr[i+1]=0;
                        size[i+1]=0;
                    }
                }

                total_file = 21-k;
                printf("\n");
            }
        } else if (opt == 2) {
            printf("Please input the file name: "); // check whether file name exists
            scanf("%d", &file_name);
            if (total_file == 0) {
                printf("NO\n");
                goto skip;
            }
            for (int i = 1; i <= 20; i++) {
                if (file_name == namearr[i]){
                    printf("YES\n");
                    break;
                } else if (i == 20 && file_name != namearr[i]) {
                    printf("NO\n");
                }
            }
            skip:;
        } else {
            return 0;
        }
    }
}