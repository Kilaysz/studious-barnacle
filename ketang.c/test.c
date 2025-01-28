#include <stdio.h>
int main()
{
    char str[] = "THE SKY IS BLUE";
    int x, y, z;
    int i, a = 200, b = 100;
    char c;

    printf("The value returned by printf() for the above string is : %d\n", printf("%s", str));

    printf("The value returned by the scanf() function is : %d",
           scanf("%d%d%d", &x, &y, &z));

    printf(" x = %d", x);
    printf(" y = %d", y);
    printf(" z = %d", z);
    printf("\n\n");

    i = scanf("%d/%d", &a, &b);
    printf("scanf return value =%d\n", i);
    while (i != 2){
        printf("Please input one more time\n");
        scanf("%d/%d", &a, &b);
    }
    // if(i != 2) i=scanf("%d/%d", &a, &b);
    printf("i=%d, %d/%d\n", i, a, b);

    return 10;
}