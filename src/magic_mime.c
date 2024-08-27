#include <stdio.h>
#include <magic.h>
#include <string.h>

const char* get_file_mime_type(const char* file_path) {
    magic_t wizard = magic_open(MAGIC_MIME);

    // TODO: 종료가 아닌 예외처리를 할 수 있도록 수정
    if (!wizard) {
        perror("magic open error: ");
        return NULL;
    }

    // magic database load
    if (magic_load(wizard, NULL) != 0) {
        perror("magic load error: ");
        magic_close(wizard);
        return NULL;
    }

    // TODO: free 필요
    const char* mime = strdup(magic_file(wizard, file_path));

    magic_close(wizard);

    return mime;
}

int main(void) {
    printf("%s\n", get_file_mime_type("/home/libmagic-practice/test/판교8월4주(2).pdf"));
    printf("%s\n", get_file_mime_type("/home/libmagic-practice/test/Hello.java"));
    printf("%s\n", get_file_mime_type("/home/libmagic-practice/test/sdasd.zip"));
    printf("%s\n", get_file_mime_type("/home/libmagic-practice/test/wordfieltst.docx"));
    printf("%s\n", get_file_mime_type("/home/libmagic-practice/test/xptmxm.pptx"));
    return 0;
}
