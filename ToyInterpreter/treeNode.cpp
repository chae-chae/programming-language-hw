#include "TreeNode.h"

TreeNode::TreeNode(string token) {
	this->token = token;
	if (token == "MINUS")
	{
		//printf("token is minus\n");
		this->isMinus = true;
		this->isIf = false;
		this->isNum = false;
	}
	else if (token == "IF") {
		//printf("token is if\n");
		this->isMinus = false;
		this->isIf = true;
		this->isNum = false;
	}
	else {
		//printf("not operator\n");
		this->isMinus = false;
		this->isIf = false;
		this->isNum = isStringInt(token);
	}
	this->leftNode = NULL;
	this->rightNode = NULL;
}

void TreeNode::View() {
	cout << this->token << endl;
}

bool TreeNode::getIsMinus() {
	return this->isMinus;
}

bool TreeNode::getIsIf() {
	return this->isIf;
}
bool TreeNode::getIsNum() {
	return this->isNum;
}

bool TreeNode::getIsLeftNum() {
	if (this->leftNode == NULL)
	{
		return false;
	}
	return this->leftNode->getIsNum();
}

bool TreeNode::getIsRightNum() {
	if (this->rightNode == NULL)
	{
		return false;
	}
	return this->rightNode->getIsNum();
}

string TreeNode::getleftNodeValue() {
	return this->leftNode->token;
}
string TreeNode::getrightNodeValue() {
	return this->rightNode->token;
}
string TreeNode::getToken() {
	return this->token;
}

void TreeNode::appendLeftChild(string token) {
	this->leftNode = new TreeNode(token);
	if (this->leftNode->isNum)
	{
		//cout << "num : " << token << endl;
	}
	else {
		//cout << "it's not a number. error!" << endl;
		leftNode->isNum = false;
	}
}

void TreeNode::appendRightChild(string token) {
	this->rightNode = new TreeNode(token);
	if (this->rightNode->isNum) {
		//cout << "num : " << token << endl;
	}
	else {
		//cout << "it's not a number. error!" << endl;
		rightNode->isNum = false;
	}
}

TreeNode::~TreeNode() { 
	//printf("TreeNode destructor\n");
	if (this->leftNode != NULL) {
		delete this->leftNode;
		//printf("delete leftnode\n");
	}
	if (this->rightNode != NULL) {
		delete this->rightNode;
		//printf("delete rightNode\n");
	}
}

bool isStringInt(string token) {
	int len = token.length();
	int j = 0;
	if ('-' == token.front())
	{
		j = 1;
	}
	for (int i = j; i < len; i++)
	{
		if (isdigit(token[i])) {
			/*cout << token[i] << endl;*/
		}
		else {
			//cout << token[i] << "not digit" << endl;
			printf("올바른 수식이 아닙니다.\n");
			return false;
		}
	}
	return true;
}