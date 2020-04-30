#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
#include "eval.h"
#include "fileLoad.h"
#include "interactiveMode.h"
#include "stack.h"
#include "Token.h"
#include "treeNode.h"

int showMenuScreen(void);
int input(void);
void MyFlush(void);

int main(int argc, const char* argv[]) {
    int menuSel;
    menuSel = showMenuScreen();
    while (menuSel != 3) {
        switch (menuSel) {
        case 1: initFile(); break;
        case 2: initIMode(); break;
        default: break;
        }
        menuSel = showMenuScreen();
    }

    printf("프로그램을 종료합니다.\n");

    return 0;
}


int showMenuScreen(void) {
    int menuSel;
    printf("\n=========================================\n");
    printf("1. File Load\n");
    printf("2. Interactive Mode\n");
    printf("3. Exit\n");
    printf("=========================================\n\n");

    menuSel = input();
    return menuSel;
}

int input(void) {
    int sel;
    while (1) {
        printf("메뉴를 선택하세요 >> ");
        scanf("%d", &sel);
        if (1 <= sel && sel <= 3 && getchar() == '\n') {
            break;
        }
        MyFlush();
    }
    return sel;
}

void MyFlush(void) {
    while (getchar() != '\n') {
        ;
    }
}

