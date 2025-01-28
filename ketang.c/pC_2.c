#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d-%d-%d", &a, &b, &c);

if (a == b && a == c){
    printf("400");
} else if (a == c && a != b){
    if (a<b){
        printf("150");
    } else {
        printf("100");
    }   
} else if (a+b<c) {
    if (a<b){
        printf("200");
    } else {
        printf("150");
    }
} else if (a<b){
     printf("50");
} else {
    printf("0");
}
}