#pragma once
#include "Token.h"

class Operator : public Token {
	Operator* left;
	Operator* right;
	string oprtr;
	string num;
	bool isMinus;
	bool isIf;
	bool isNum;
public:
	Operator(string oprtr);
	void View();
	~Operator();
};