#include <stdio.h>

int main()
{
    long long a,b,c;
    scanf("%lld%lld",&a,&b);    
    
    if ((a<0 && b>0)||(a>0 && b<0)){
        printf("No");
    } else if (a>0 && b>0){
        c = a + b - 9223372036854775807;
        if (c > 0){
            printf("Yes");
        } else {
            printf("No");
        }
    } else if (a<0 && b<0){
        c = a+b + 9223372036854775808;
        if (c < 0){
            printf("Yes");
        } else {
            printf("No");
        }
    }

    return 0;
}