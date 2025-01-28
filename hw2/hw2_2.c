#include <stdio.h>
#include <math.h>
int main(){
    int n, k1, k2, k3, result;
    scanf("%d %d %d %d", &n, &k1, &k2, &k3);
    result=n*((k1-floor(k1/3))+(k2-floor(k2/3))+(k3-floor(k3/3)));
    printf("%d", result);

    return 0;
}