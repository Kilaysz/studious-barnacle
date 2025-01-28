#include <stdio.h>

int fibonacci(int a){
    if(a<=1){
        return a; 
    } else {
    return fibonacci(a-1)+fibonacci(a-2);
    }
}

int main(){
    int a;
    scanf("%d", &a);
    printf("%d", fibonacci(a));
    return 0;
}