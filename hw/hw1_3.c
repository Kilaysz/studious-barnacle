#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    float result;
    result = sqrt(a*c)+pow(a, b)+log10(a*b*c);
    printf("%.3f", result);
    return 0;
}