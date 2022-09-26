#include "command.h"
#include "coder.h"

int encode_file(const char* in_file_name, const char* out_file_name)
{
    FILE* input;
    FILE* output;

    if ((input = fopen(in_file_name, "r")) == NULL) {
        return -1;
    }
    if ((output = fopen(out_file_name, "wb")) == NULL) {
        return -1;
    }

    CodeUnits code_unit;
    uint32_t code_point;

    while (fscanf(input, "%" SCNx32, &code_point)
           == 1) { // считываем данные из потока input
        encode(code_point, &code_unit);
        write_code_unit(output, &code_unit);
    }
    fclose(input);
    fclose(output);
    return 0;
}

int decode_file(const char* in_file_name, const char* out_file_name)
{
    FILE* input;
    FILE* output;
    if ((input = fopen(in_file_name, "rb")) == NULL) {
        return -1;
    }
    if ((output = fopen(out_file_name, "w+")) == NULL) {
        return -1;
    }
    CodeUnits code_unit;
    while (!read_next_code_unit(input, &code_unit)) {
        if (code_unit.code[0] != 0) {
            if (!fprintf(output, "%" PRIx32 "\n", decode(&code_unit))) {
                return -1;
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}