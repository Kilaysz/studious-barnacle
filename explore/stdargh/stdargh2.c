#include <stdio.h>
#include <math.h>
#include <stdarg.h>

double poly(int degree, ...){
    va_list ap;
    double result = 0.0, coefficient;
    va_start(ap, degree);
    double x = va_arg(ap, double);
    for(int i = 0; i<=degree;i++){
        coefficient = va_arg(ap, double);    
        result += coefficient*pow(x, i);
    }
    va_end(ap);
    return result;
}

unsigned main(){
    printf("%lf", poly(2, 2.0, 3.0, 4.0, 2.0));
    return 0;
}