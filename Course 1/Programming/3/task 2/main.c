#include "coder.h"
#include "command.h"
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Для запуска используйте:\n"
               "coder encode <in-file-name> <out-file-name>, или\n"
               "coder decode <in-file-name> <out-file-name>\n");
        return -1;
    }
    if (!strcmp(argv[1], "decode")) {
        if (decode_file(argv[2], argv[3])) {
            printf("Указан несуществующий файл\n");
            return -1;
        }
        printf("Ok\n");
    } else if (!strcmp(argv[1], "encode")) {
        if (encode_file(argv[2], argv[3])) {
            printf("Указан несуществующий файл\n");
            return -1;
        }
        printf("Ok\n");
    } else {
        printf("Для запуска используйте:\n"
               "coder encode <in-file-name> <out-file-name>, или\n"
               "coder decode <in-file-name> <out-file-name>\n");
        return -1;
    }
    return 0;
}
