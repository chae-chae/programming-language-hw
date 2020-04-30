#include "interactiveMode.h"
#include "Token.h"
#include "string.h"

void initIMode(void) {
	Token token;
	printf("문장을 입력하세요.\n");
	printf("-----------------------------------------\n");
	char expr[100];
	fgets(expr, 100, stdin);
	printf("-----------------------------------------\n");
	int len = strlen(expr);
	expr[len-1] = '\0';
	token.initToken(expr);
}