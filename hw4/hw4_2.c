#include <stdio.h>

long double factorial(double a){ // subprogram
    for(int i = a-1; i>=1; i--){
        a *= i;
    }
    return a;
}

int main(){
int n;
long double y=1;
scanf("%d", &n);
    for(int i = 1; i<=n;i++){
        y += 1/(factorial(i));
    }
printf("%.18Lf", y);
}
