#include <stdio.h>

union FloatOrDouble {
    float floatValue;
    double doubleValue;
    unsigned int floatBits;
    unsigned long long doubleBits;
};

void convertFloatOrDouble(union FloatOrDouble *data, int bitsize) {
    if (bitsize == 32) {
        printf("Enter a float number: ");
        scanf("%f", &(data->floatValue));

        printf("Binary representation: ");
        for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i) {
            printf("%d", (data->floatBits >> i) & 1);
        }
        printf("\n");

        printf("Enter the binary pattern (32 bits) for float: ");
        for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i) {
            int bit;
            scanf("%1d", &bit);
            data->floatBits = (data->floatBits << 1) | bit;
        }

        printf("Value of bit pattern is: %.2f\n", data->floatValue);
    } else if (bitsize == 64) {
        printf("Enter a double number: ");
        scanf("%lf", &(data->doubleValue));

        printf("Binary representation: ");
        for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i) {
            printf("%llu", (data->doubleBits >> i) & 1);
        }
        printf("\n");

        printf("Enter the binary pattern (64 bits) for double: ");
        for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i) {
            int bit;
            scanf("%1d", &bit);
            data->doubleBits = (data->doubleBits << 1ULL) | bit;
        }

        printf("Value of bit pattern is: %.2lf\n", data->doubleValue);
    } else {
        printf("Invalid bit size. Supported sizes are 32 and 64 bits.\n");
    }
}

int main() {
    union FloatOrDouble data;

    // Choose the desired bit size (32 or 64)
    int bitsize;
    printf("Choose the bit size (32 or 64): ");
    scanf("%d", &bitsize);

    convertFloatOrDouble(&data, bitsize);

    return 0;
}
