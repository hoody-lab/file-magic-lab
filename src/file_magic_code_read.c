#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file;
    unsigned char magic_codes[20];
    char* file_path = "/home/libmagic-practice/test/판교8월4주(2).pdf";

    file = fopen(file_path, "rb");

    if (file == NULL) {
        perror("file read error!");
        return -1;
    }

    // 읽은 데이터를 저장할 변수 포인터, 데이터 하나의 크기, 데이터 전체 크기, 파일 포인터
    // 반환값은 읽어들인 데이터의 사이즈를 반환하며, 실제 데이터는 magic_codes에 저장된다.
    size_t byte_size = fread(magic_codes, 1, sizeof(magic_codes), file);

    if (byte_size == 0) {
        perror("file byte read error!");
        return -1;
    }

    printf("file magic code: ");
    // use C99 mode
    // for (size_t i = 0; i < byte_size; i++) {
    //     printf("%02x ", magic_codes[i]);
    // }
    size_t i;
    for (i = 0; i < byte_size; i++) {
        printf("%02x ", magic_codes[i]);
    }
    printf("\n");

    fclose(file);

    return 0;
}
