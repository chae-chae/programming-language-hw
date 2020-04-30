#pragma once
#include <iostream>
#include <string.h>

//#include <vector>
using namespace std;
bool isStringInt(string token);

class Token

{

public:

    void makeTree(string sentence);
    void parseInt(string sentence, int i, string* left, string* right);
    void initToken(char* textColumn);
    /*bool isStringInt(string token);*/
    ~Token();
};