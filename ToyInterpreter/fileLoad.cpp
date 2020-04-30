#include "fileLoad.h"
#include "Token.h"

char* loadFile(void) {
    char filename[100];
    char* text;
    FILE* fp;
    long size;

    printf("���ϸ��� �Է��ϼ��� >> ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    while (fp == NULL) {
        printf("������ ã�� �� �����ϴ�. �ٽ� �Է����ּ���\n");
        printf("���ϸ��� �Է��ϼ��� >> ");
        scanf("%s", filename);
        fp = fopen(filename, "r");
    }

    fseek(fp, 0, SEEK_END); // ������ ���� ������ fp�� �ű�
    size = ftell(fp); // �ű� �� ������ġ ����
    text = (char*)malloc(size + 1); // null����
    memset(text, 0, size + 1); // ���� ũ�� + 1����Ʈ��ŭ �޸𸮸� 0���� �ʱ�ȭ
    fseek(fp, 0, SEEK_SET); // �ٽ� fp�� ������ ó������ �ǵ���
    fread(text, size, 1, fp); // text�� ���ϳ�������
    printf("\n���� ������ \n");
    printf("-----------------------------------------\n");
    printf("%s\n", text);
    printf("-----------------------------------------\n");
    printf("�Դϴ�. \n\n");
    fclose(fp);

    return text;
}

int cutString(char* text, char* textColumn[]) {
    char* tokptr = strtok(text, "\n"); // ���ึ�� �ڸ�
    int i = 0; // textColumn�� �ε���
    while (tokptr != NULL) { // �߶�ִ� ����
        textColumn[i] = tokptr;
        i++;
        tokptr = strtok(NULL, "\n");
    }
    return i;
}

void initFile(void) {
    Token token;
    char* text;
    char* textColumn[MAX] = { NULL, }; // text ������ ���ึ�� �߶� ������ char*���� �迭
    int columnSize = 0;
    text = loadFile();
    columnSize = cutString(text, textColumn);
    for (int i = 0; i < columnSize; i++)
    {
        //printf("textColumn[%d] : %s\n", i, textColumn[i]);
        token.initToken(textColumn[i]);
    }
    
}