#include <stdio.h>

int power(int x, int N){
    if(N==0){
        return 1;
    } else {
        return x*power(x, N-1);
    }
}

int main(){
int a, b;
scanf("%d %d", &a, &b);
printf("%d", power(a, b));
}