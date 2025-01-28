#include <stdio.h>

int main()
{
    char str[] = "THE SKY IS BLUE";

    printf("The value returned by printf() for the above string is : %d\n", printf("%s\n", str));
    int x, y, z;
    printf("The value returned by the scanf() function is : %d",
           scanf("%d%d%d", &x, &y, &z));
    printf("\nx = %d", x);
    printf(" y = %d", y);
    printf(" z = %d", z);
    printf("\n\n");
    int i, a = 200, b = 100;
    i = scanf("%d/%d", &a, &b);
    printf("scanf return value =%d\n", i);
    if (i != 3){
        char c;
        while ((c = getchar()) != '\n' && c != EOF);
        i = scanf("%d/%d", &a, &b);
    }
    printf("%d/%d\n", a, b);
    return 0;
}

// 1. Compile and Run this C program.
// 2. modify the program to make the output clear by using '\n'
// 3. In command line, try to run command 'echo $?' to know the meaning of shell variable $?