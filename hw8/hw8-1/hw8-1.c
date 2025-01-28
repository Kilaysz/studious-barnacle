#include <stdio.h>
#include <stdlib.h>
#include "hw8-1.h"

void init(int*** mp) {
for (int i = 0; i < 130; i++) {
    mp[i] = (int**)malloc( 130 * sizeof(int*) ); 
    for (int j = 0; j < 130; j++) {
        mp[i][j] = (int*)malloc( 130 * sizeof(int) ); 
    }
}

    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = 'A'; j <= 'Z'; j++) {
            for (int k = 'A'; k <= 'Z'; k++) {
                mp[i][j][k] = 1;
            }
        }
    }
}

void modify(int* a,int val){
    *a = val;
}

int query(int**** mp,char a[4],char b[4]){
    int result_1, result_2;
    result_1 = *(*(*(*(mp)+a[0])+a[1])+a[2]);
    result_2 = *(*(*(*(mp)+b[0])+b[1])+b[2]);
    if((result_1+result_2)%2!=0){
        return 1;
    } else{
        return 0;
    }
}