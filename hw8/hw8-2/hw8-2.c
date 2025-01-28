#include <stdio.h>
#include <stdlib.h>
#include "hw8-2.h"
int check;
void modify(int* a,int val){ 
    *a = val%2;
}
int query(int (*mp)[131][131][131],char a[4],char b[4]){
    if(check==0){
    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = 'A'; j <= 'Z'; j++) {
            for (int k = 'A'; k <= 'Z'; k++) {
                (*mp)[i][j][k] = 1;
            }
        }
    }
        check = 1;
    }
    int num1, num2;
    num1 = (*mp)[a[0]][a[1]][a[2]];
    num2 = (*mp)[b[0]][b[1]][b[2]];
    return ((num1 + num2)%2!=0)?1:0;
}