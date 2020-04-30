#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
#define MAX 100

char* loadFile(void);
int cutString(char* text, char* textColumn[]);
void initFile(void);