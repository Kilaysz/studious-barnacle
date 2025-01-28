#include <stdio.h>
#include <math.h>

int main(){
    int N;
    scanf("%d", &N); 
    N = (floor(N/100)*100 + floor(N%10)*10 + floor(N%100/10))*2023; 
    printf("%d", N);
    return 0;  
}