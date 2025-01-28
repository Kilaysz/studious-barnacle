#include <stdio.h>


int calculate(int a, int b, int N){
    int result;
    result = (b << a) + (a|b)-(N>>b)*(a^b)-(a&b);
    return result;
}

int main(){
    int a,b,N;
    scanf("%d,%d,%d", &a, &b, &N);
    printf("%d", calculate(a,b,N));
}