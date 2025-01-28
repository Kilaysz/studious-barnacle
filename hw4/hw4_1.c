#include <stdio.h>

int main()
{
    int days,starting_day;
    printf("Enter number of days in month: \n");
    scanf("%d",&days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): \n");
    scanf("%d",&starting_day);

    for (int i = 1; i <= 3*starting_day-3; i++){ // identation in first line
        printf(" ");
    }
    
   for(int i = 1; i <= days; i++){ 
        if((i+starting_day-1)%7==0 && i != days){
            printf("%2d\n", i);
        } else if((i+starting_day-1)%7==0){
            printf("%2d", i);
        } else {
            if(i==days){
            printf("%2d", i);
            } else {
            printf("%2d ", i);
            }
        }
   }
    
    return 0;
}
      