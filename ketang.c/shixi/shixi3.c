#include <stdio.h>

void decimalToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    } 
    int binary[32];
    int index = 0;

    while(num>0){
        binary[index]=num%2;
        num /= 2;
        index++;
    }

    for(int i = index-1; i>=0; i--){
        printf("%d", binary[i]);
    }
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decimalToBinary(num);
    return 0;
}