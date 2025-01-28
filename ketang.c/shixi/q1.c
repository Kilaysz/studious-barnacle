#include<stdio.h>

int Z_X(int x){
    int result;
    result = 2023-5*x;
    return result;
}

int Y_X(int Z_X){
    int result;
    result = 6*Z_X+10;
    return result;
}


int main(){
int input, a, b, result;
scanf("%d", &input);
a = Z_X(input);
b = Y_X(a);
result = b+7*input;
printf("%d", result);
}