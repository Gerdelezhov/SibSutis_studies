#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Диапазон             Вероятность
 * -------------------- -----------
 * [0; 128)             90%
 * [128; 16384)         5%
 * [16384; 2097152)     4%
 * [2097152; 268435455) 1%
 */
uint32_t generate_number()
{
    const int r = rand();
    const int p = r % 100;
    if (p < 90) {
        return r % 128;
    }
    if (p < 95) {
        return r % 16384;
    }
    if (p < 99) {
        return r % 2097152;
    }
    return r % 268435455;
}

size_t encode_varint(uint32_t value, uint8_t* buf)
{
    assert(buf != NULL);
    uint8_t* cur = buf;
    while (value >= 0x80) {
        const uint8_t byte = (value & 0x7f) | 0x80;
        *cur = byte;
        value >>= 7;
        ++cur;
    }
    *cur = value;
    ++cur;
    return cur - buf;
}

uint32_t decode_varint(const unsigned char** bufp)
{
    const unsigned char* cur = *bufp;
    uint8_t byte = *cur++;
    uint32_t value = byte & 0x7f;
    size_t shift = 7;
    while (byte >= 0x80) {
        byte = *cur++;
        value += (byte & 0x7f) << shift;
        shift += 7;
    }
    *bufp = cur;
    return value;
}

int main()
{
    srand(time(NULL));

    uint8_t buf[4];
    uint32_t generate_number();
    int status = 0;

    FILE* uncom;
    FILE* com;
    uncom = fopen("uncompressed.dat", "wb");
    com = fopen("compressed.dat", "wb");

    for (int i = 0; i < 1000000; i++) {
        uint32_t value = generate_number();
        fwrite(&value, sizeof(uint32_t), 1, uncom);
        size_t size = encode_varint(value, buf);
        fwrite(buf, sizeof(uint8_t), size, com);
    }

    fclose(uncom);
    fclose(com);

    uncom = fopen("uncompressed.dat", "rb");
    com = fopen("compressed.dat", "rb");

    printf("До сжатия    После\n");

    int size;
    uint8_t* comp_numbers;
    const uint8_t* p;
    fseek(com, 0, SEEK_END);
    size = ftell(com);
    fseek(com, 0, SEEK_SET);
    comp_numbers = malloc(sizeof(uint8_t) * size);
    p = comp_numbers;

    for (int i = 0; i < size; i++) {
        fread(&comp_numbers[i], sizeof(uint8_t), 1, com);
    }

    for (int i = 0; i < 1000000; i++) {
        uint32_t valueUncom = 0;
        uint32_t valueCom = 0;

        fread(&valueUncom, sizeof(uint8_t), sizeof(uint32_t), uncom);
        valueCom = decode_varint(&p);

        if (i % 200000 == 0) {
            printf("%-12d %d\n", valueUncom, valueCom);
        }
        if (valueUncom != valueCom) {
            status = 1;
        }
    }
    if (status == 1) {
        printf("NOT OK\n");
    } else {
        printf("\n-------\nOK\n");
    }
    return 0;
}