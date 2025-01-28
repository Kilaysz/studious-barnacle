#include <stdio.h>

int gcd(int p, int q){
    int r;
    if((r = p%q)==0){
        return q;
    } else {
        return gcd(q, r);
    }
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}