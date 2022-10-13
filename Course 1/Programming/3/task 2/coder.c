#include "coder.h"

int encode(uint32_t code_point, CodeUnits* code_units)
{
    uint8_t count = 0;
    for (uint32_t i = code_point; i > 0; i >>= 1) {
        count++; // подсчет кол-ва битов
    }
    if (count <= 7) // для 1-го байта
    {
        code_units->code[0] = code_point;
        code_units->length = 1;
        return 0;
    } else if (count <= 11) { // для 2-х байтов
        code_units->code[0] = (code_point >> 6) | (3 << 6); // 3 = 11
        code_units->code[1] = (code_point & ~(1 << 6)) | (1 << 7);
        code_units->length = 2;
        return 0;

    } else if (count <= 16) { // для 3-х байтов
        code_units->code[0] = (code_point >> 12) | (7 << 5); // 7 == 111
        code_units->code[1] = ((code_point >> 6) & ~(1 << 6)) | (1 << 7);
        code_units->code[2] = (code_point & ~(1 << 6)) | (1 << 7);
        code_units->length = 3;
        return 0;

    } else if (count <= 21) { //  для 4-х байтов
        code_units->code[0] = (code_point >> 18) | (15 << 4); // 15 ==1111
        code_units->code[1] = ((code_point >> 12) & ~(1 << 6)) | (1 << 7);
        code_units->code[2] = ((code_point >> 6) & ~(1 << 6)) | (1 << 7);
        code_units->code[3] = (code_point & ~(1 << 6)) | (1 << 7);
        code_units->length = 4;
        return 0;
    }
    return -1;
}
uint32_t decode(const CodeUnits* code_unit)
{
    uint32_t code_point;
    if (code_unit->length == 1) {
        return (code_point = code_unit->code[0]);

    } else if (code_unit->length == 2) {
        code_point = (code_unit->code[0] & 31) << 6;         // 31 == 00011111
        code_point = code_point | (code_unit->code[1] & 63); // 63 == 00111111
        return code_point;
    } else if (code_unit->length == 3) {
        code_point = (code_unit->code[0] & 15) << 6;
        code_point = (code_point | (code_unit->code[1] & 63)) << 6;
        code_point = code_point | (code_unit->code[2] & 63);
        return code_point;
    } else if (code_unit->length == 4) {
        code_point = (code_unit->code[0] & 7) << 6; //  7 = 00000111
        code_point = (code_point | (code_unit->code[1] & 63)) << 6;
        code_point = (code_point | (code_unit->code[2] & 63)) << 6;
        code_point = code_point | (code_unit->code[3] & 63);
        return code_point;
    }
    return 0;
}
int read_next_code_unit(
        FILE* in,
        CodeUnits* code_unit) //считывание последовательности из потока in
{
    uint8_t byte;
    fread(&byte, sizeof(uint8_t), 1, in);
    if ((byte & 0xF0) == 0xF0) {
        code_unit->length = 4;
    } else if ((byte & 0xE0) == 0xE0) {
        code_unit->length = 3;
    } else if ((byte & 0xC0) == 0xC0) {
        code_unit->length = 2;
    } else if ((byte >> 7) == 0)
        code_unit->length = 1;
    else {
        code_unit->length = 0;
        return 0;
    }

    code_unit->code[0] = byte;
    if (code_unit->length != 1) {
        for (int i = 1; i < code_unit->length; i++) {
            if (!fread(code_unit->code + i, sizeof(uint8_t), 1, in))
                return -1;
        }
    }
    return 0;
}

int write_code_unit(FILE* out, const CodeUnits* code_unit)
{
    for (int i = 0; i < code_unit->length; i++) {
        fwrite(&code_unit->code[i], sizeof(uint8_t), 1, out);
    }
    return 0;
}
