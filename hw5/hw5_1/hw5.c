#include <stdio.h>

int gcd(int a, int b, int c){
    for(int i = a; i>=1; i--){
        if(a%i==0&&b%i==0&&c%i==0){
            return i;
            break;
        }
    }
}

int main(){
    int a, count=0, K1, K2, K3, KirbyA = 0, KirbyB = 0, KirbyC = 0, price=0;
    printf("//////////Welcome to NCKU-PD1-Kirby-Shop\\\\\\\\\\\\\\\\\\\\\n");
    printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
    scanf("%d", &a);
    while(a != 4){
      switch (a){
        case 4:
            a = 4;
            return 0;
            break;
        case 3:
        if(count>=1){
            printf("Please enter three numbers: ");
            scanf("%d %d %d", &K1, &K2, &K3);
            if(K1>=0&&K2>=0&&K3>=0){  
                KirbyA += K1;
                KirbyB += K2;
                KirbyC += K3;
                price += K1+K2+K3-2*gcd(K1,K2,K3);
                printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\n", gcd(K1,K2,K3), K1/gcd(K1,K2,K3), K2/gcd(K1,K2,K3), K3/gcd(K1,K2,K3));
                printf("Price: %d\n", K1+K2+K3-2*gcd(K1,K2,K3));
            } else {
                    printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                    scanf("%d %d %d", &K1, &K2, &K3);
                    while(!(K1>=0&&K2>=0&&K3>=0)){
                        if(K1==-1&&K2==-1&&K3==-1){
                            break; 
                        } else {
                            printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                            scanf("%d %d %d", &K1, &K2, &K3);
                            if(K1>=0&&K2>=0&&K3>=0){
                            KirbyA += K1;
                            KirbyB += K2;
                            KirbyC += K3;
                            price += K1+K2+K3-2*gcd(K1,K2,K3);
                            printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\n", gcd(K1,K2,K3), K1/gcd(K1,K2,K3), K2/gcd(K1,K2,K3), K3/gcd(K1,K2,K3));
                            printf("Price: %d\n", K1+K2+K3-2*gcd(K1,K2,K3));
                            break;
                            } 
                        }
                    }
            }
        } else {
            printf("Your Kirby shop has not opened\n");
            }            
            printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
            scanf("%d", &a);
            break;
        case 2:
        if(count>=1){
            printf("===================================\n");
            printf("Kirby-A: %d\n", KirbyA);
            printf("Kirby-B: %d\n", KirbyB);
            printf("Kirby-C: %d\n", KirbyC);
            printf("Kirby: %d, Money: %d\n", KirbyA+KirbyB+KirbyC, price);
            printf("===================================\n");
        } else {
            printf("Your Kirby shop has not opened\n");
        }
            printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
            scanf("%d", &a);
            break;
        case 1:
            count +=1;
            if(count==1){
                printf("Your shop is openning!\n");
            } else if(count>1){
                printf("Your Kirby shop has already opened :(\n");
            } else {
                printf("Error: Please try again!\n");            
            }
            printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
            scanf("%d", &a);
            break;
        default:
            printf("Error: Please try again!\n");
            printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
            scanf("%d", &a);
        }
    }
}