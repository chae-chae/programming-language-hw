#pragma once
#include "Token.h"
bool isStringInt(string token);
class TreeNode /*: public Token*/ {
	TreeNode* leftNode;
	TreeNode* rightNode;
	string token;
	bool isMinus;
	bool isIf;
	bool isNum;
public:
	TreeNode(string oprtr);
	void View();
	bool getIsMinus();
	bool getIsIf();
	bool getIsNum();
	bool getIsLeftNum();
	bool getIsRightNum();
	string getleftNodeValue();
	string getrightNodeValue();
	string getToken();
	void appendLeftChild(string token);
	void appendRightChild(string token);
	~TreeNode();
};