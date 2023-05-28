#include <stdio.h>
#include <stdint.h>

// Structure with data alignment optimization
typedef struct {
    uint32_t a;
    uint16_t b;
    uint8_t c;
} __attribute__((packed)) AlignedStruct;

int main() {
    AlignedStruct data;

    printf("Size of AlignedStruct: %zu\n", sizeof(AlignedStruct));
    printf("Address of 'a': %p\n", &data.a);
    printf("Address of 'b': %p\n", &data.b);
    printf("Address of 'c': %p\n", &data.c);

    return 0;
}
