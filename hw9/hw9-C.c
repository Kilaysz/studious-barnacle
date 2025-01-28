#include <stdio.h>
#include <stdint.h>

union FloatOrDouble {
    float float_num;
    double double_num;
    struct {
        uint32_t mantissa;
        uint32_t exponent;
        uint32_t sign;
    } float_bits;
    struct {
        uint64_t mantissa;
        uint64_t exponent;
        uint64_t sign;
    } double_bits;
};

void printBitPattern(union FloatOrDouble num, size_t bitSize) {
    size_t size = bitSize / 8;

    for (size_t i = 0; i < bitSize; ++i) {
        if (size == sizeof(num.double_num)) {
            printf("%llu", (num.double_bits.sign >> (bitSize - 1 - i)) & 1);
        } else if (size == sizeof(num.float_num)) {
            printf("%u", (num.float_bits.sign >> (bitSize - 1 - i)) & 1);
        }
    }
    printf(" ");

    for (size_t i = 0; i < bitSize; ++i) {
        if (size == sizeof(num.double_num)) {
            printf("%llu", (num.double_bits.exponent >> (bitSize - 1 - i)) & 1);
        } else if (size == sizeof(num.float_num)) {
            printf("%u", (num.float_bits.exponent >> (bitSize - 1 - i)) & 1);
        }
    }
    printf(" ");

    for (size_t i = 0; i < bitSize; ++i) {
        if (size == sizeof(num.double_num)) {
            printf("%llu", (num.double_bits.mantissa >> (bitSize - 1 - i)) & 1);
        } else if (size == sizeof(num.float_num)) {
            printf("%u", (num.float_bits.mantissa >> (bitSize - 1 - i)) & 1);
        }
    }
    printf("\n");
}

int main() {
    union FloatOrDouble num;

    printf("Enter a float or double number: ");
    scanf("%lf", &num.double_num);

    size_t bitSize;
    printf("Enter the bit size (32 or 64): ");
    scanf("%zu", &bitSize);

    printf("Bit pattern: ");
    printBitPattern(num, bitSize);

    printf("Enter the bit pattern: ");
    scanf("%llu %llu %llu", &num.double_bits.sign, &num.double_bits.exponent, &num.double_bits.mantissa);

    printf("Value: %lf\n", num.double_num);

    return 0;
}
