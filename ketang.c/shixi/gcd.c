#include <stdio.h>

int gcd(int n, int m){
for (int i = m; i >=1; i--){
    if(m%i==0&&n%i==0){
        return i;
        break;
    }
}
}

int main(){
    printf("Please input two integer and get their GCD(greastest common divisor).\n");
    int n, m;
    scanf("%d%d", &n, &m);
   
    printf("The GCD of the two numbers is %d.\n", gcd(n,m));
    return 0;
}