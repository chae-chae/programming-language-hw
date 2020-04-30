#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Stack {
private:
    string data[MAX];
    int index;
public:
    Stack();
    bool IsEmpty();
    void push(string token);
    string pop();
    int size();
    void view();
    ~Stack();
};

