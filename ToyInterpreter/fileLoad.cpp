#include "fileLoad.h"
#include "Token.h"

char* loadFile(void) {
    char filename[100];
    char* text;
    FILE* fp;
    long size;

    printf("파일명을 입력하세요 >> ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    while (fp == NULL) {
        printf("파일을 찾을 수 없습니다. 다시 입력해주세요\n");
        printf("파일명을 입력하세요 >> ");
        scanf("%s", filename);
        fp = fopen(filename, "r");
    }

    fseek(fp, 0, SEEK_END); // 파일의 가장 끝까지 fp를 옮김
    size = ftell(fp); // 옮긴 후 현재위치 저장
    text = (char*)malloc(size + 1); // null문자
    memset(text, 0, size + 1); // 파일 크기 + 1바이트만큼 메모리를 0으로 초기화
    fseek(fp, 0, SEEK_SET); // 다시 fp를 파일의 처음으로 되돌림
    fread(text, size, 1, fp); // text에 파일내용저장
    printf("\n파일 내용은 \n");
    printf("-----------------------------------------\n");
    printf("%s\n", text);
    printf("-----------------------------------------\n");
    printf("입니다. \n\n");
    fclose(fp);

    return text;
}

int cutString(char* text, char* textColumn[]) {
    char* tokptr = strtok(text, "\n"); // 개행마다 자름
    int i = 0; // textColumn의 인덱스
    while (tokptr != NULL) { // 잘라넣는 과정
        textColumn[i] = tokptr;
        i++;
        tokptr = strtok(NULL, "\n");
    }
    return i;
}

void initFile(void) {
    Token token;
    char* text;
    char* textColumn[MAX] = { NULL, }; // text 내용을 개행마다 잘라서 저장할 char*들의 배열
    int columnSize = 0;
    text = loadFile();
    columnSize = cutString(text, textColumn);
    for (int i = 0; i < columnSize; i++)
    {
        //printf("textColumn[%d] : %s\n", i, textColumn[i]);
        token.initToken(textColumn[i]);
    }
    
}