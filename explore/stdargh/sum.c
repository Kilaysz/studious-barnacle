#include <stdio.h>
#include <stdarg.h>

void sum(int n, ...){
    va_list ap;
    va_start(ap, n);
    double sum = 0.0;
    for(int i = 1;i<=n;i++){
        double x=va_arg(ap, double);
        sum += x;
    }
    va_end(ap);
    printf("%.2lf\n", sum);
    return;
}

void product(int n, ...){
    va_list ap;
    va_start(ap, n);
    double product = 1;
    for(int i = 1;i<=n;i++){
        double x=va_arg(ap, double);
        product *= x;
    }
    va_end(ap);
    printf("%.2lf", product);
    return;
}



int main(){
    sum(6, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
    product(6, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
    return 0;
}
