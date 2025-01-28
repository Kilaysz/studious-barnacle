#include <stdio.h>

// Technique (a): Using an integer pointer
void floatToBinary(float num) {
    unsigned int *ptr = (unsigned int *)&num; 
    printf("%.2f in binary: ", num); 
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i) { // for 32 bit
        printf("%d", (*ptr >> i) & 1); 
    }
    
    printf("\n");
}

void doubleToBinary(double num) {
    unsigned long long *ptr = (unsigned long long *)&num;
    printf("%.2lf in binary: ", num);
    
    for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i) {
        printf("%llu", (*ptr >> i) & 1);
    }
    
    printf("\n");
}

void binaryToFloat(const char *binary) {
    unsigned int bits = 0;
    for (int i = 0; i < sizeof(unsigned int) * 8; ++i) {
        bits = (bits << 1) | (binary[i] - '0');
    }
    
    float *ptr = (float *)&bits;
    printf("Value of bit pattern %s is: %.2f\n", binary, *ptr);
}

void binaryToDouble(const char *binary) {
    unsigned long long bits = 0;
    for (int i = 0; i < sizeof(unsigned long long) * 8; ++i) {
        bits = (bits << 1) | (binary[i] - '0');
    }
    
    double *ptr = (double *)&bits;
    printf("Value of bit pattern %s is: %.2lf\n", binary, *ptr);
}

int main() {
    int choice;
    
    printf("Choose an operation:\n");
    printf("1. Float to Binary\n");
    printf("2. Double to Binary\n");
    printf("3. Binary to Float\n");
    printf("4. Binary to Double\n");
    printf("Enter 1, 2, 3, or 4: ");
    
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            float num;
            printf("Enter a float number: ");
            scanf("%f", &num);
            floatToBinary(num);
            break;
            
        case 2:
            double dnum;
            printf("Enter a double number: ");
            scanf("%lf", &dnum);
            doubleToBinary(dnum);
            break;
            
        case 3:
            char binaryFloat[32];
            printf("Enter the binary pattern (32 bits) for float: ");
            scanf("%s", binaryFloat);
            binaryToFloat(binaryFloat);
            break;
            
        case 4:
            char binaryDouble[64];
            printf("Enter the binary pattern (64 bits) for double: ");
            scanf("%s", binaryDouble);
            binaryToDouble(binaryDouble);
            break;
            
        default:
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
            break;
    }

    return 0;
}
