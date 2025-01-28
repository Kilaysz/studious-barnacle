#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Using rand() to generate a random number between 1 and 6.
int rollDice(){
    return (rand()%6)+1;
}

int main() {
    srand((unsigned)time(NULL));
    int totalRolls = 10000; // you could modify the totalRolls
    double expectedValue = 0;
    int sum = 0;

    for (int i = 1; i <= totalRolls; i++){
        sum += rollDice();
    }
    expectedValue= (double) sum /totalRolls;
    printf("The Expected Value is %lf\n", expectedValue);
    return 0;
}