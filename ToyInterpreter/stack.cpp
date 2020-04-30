#include "stack.h"

Stack::Stack() {
    this->index = -1;
}

bool Stack::IsEmpty() {
    if (this->index == -1) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::push(string token) {
    index += 1;
    data[index] = token;
}

string Stack::pop() {
    string res = data[index];
    index -= 1;
    return res;
}

int Stack::size() {
    return index + 1;
}

void Stack::view() {
    for (int i = 0; i <= index; i++)
    {
        cout << "stack [" << i << "] : " << this->data[i] << endl;
    }
}

Stack::~Stack() { 
    //printf("Stack destructor\n"); 
}