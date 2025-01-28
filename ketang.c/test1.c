#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c;
    scanf("(%lf,%lf,%lf)",&a,&b,&c);
    
    double s = ( a + b + c ) / 2;
    double ans = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("%lf\n", s);
    printf("%lf\n", ans);
    printf("%d", (int)ans);
}