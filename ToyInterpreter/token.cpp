#include "Token.h"
#include "stack.h"
#include "treeNode.h"
#include "eval.h"

//#include <iostream>
//using namespace std;

void Token::makeTree(string sentence) { // parse tree
	//cout << sentence << endl;
	int mI, iI;
	mI = sentence.find("MINUS");
	iI = sentence.find("IF");
	if (mI == 1 && iI == -1) {
		//printf("MINUS\n");
		TreeNode rootnode("MINUS");
		int i = 7;
		string left;
		string right;
		parseInt(sentence, i, &left, &right);
		//cout << "left num : " << left << " right num : " << right << endl;
		rootnode.appendLeftChild(left);
		if (rootnode.getIsLeftNum() == false) // ���ھƴϸ�
		{
			//printf("left num ���ھƴ�\n");
			return;
		}
		rootnode.appendRightChild(right);
		if (rootnode.getIsRightNum() == false)
		{
			//printf("right num ���ھƴ�\n");
			return;
		}
		//cout << '(' << rootnode.getToken() << ' ' << rootnode.getleftNodeValue() << ' ' << rootnode.getrightNodeValue() << ')' << endl;
		Stack numbers;
		Stack ops;
		numbers.push(rootnode.getleftNodeValue());
		numbers.push(rootnode.getrightNodeValue());
		//numbers.view();
		ops.push(rootnode.getToken());
		//ops.view();
		evaluate(numbers, ops);
	}
	else if (mI == -1 && iI == 1) {
		//printf("IF\n");
		TreeNode rootnode("IF");
		int i = 4;
		string left;
		string right;
		parseInt(sentence, i, &left, &right);
		//cout << "left num : " << left << " right num : " << right << endl;
		rootnode.appendLeftChild(left);
		if (rootnode.getIsLeftNum() == false) // ���ھƴϸ�
		{
			//printf("left num ���ھƴ�\n");
			return;
		}
		rootnode.appendRightChild(right);
		if (rootnode.getIsRightNum() == false)
		{
			//printf("right num ���ھƴ�\n");
			return;
		}
		//cout << '(' << rootnode.getToken() << ' ' << rootnode.getleftNodeValue() << ' ' << rootnode.getrightNodeValue() << ')' << endl;
		Stack numbers;
		Stack ops;
		numbers.push(rootnode.getleftNodeValue());
		numbers.push(rootnode.getrightNodeValue());
		//numbers.view();
		ops.push(rootnode.getToken());
		//ops.view();
		evaluate(numbers, ops);
	} 	
	else if (mI == -1 && iI == -1) {
		printf("�ùٸ� ������ �ƴմϴ�.\n");
	}
	else {
		printf("�ùٸ� ������ �ƴմϴ�.\n");
	}
}


void Token::initToken(char *textColumn) {
	Stack result;
	if (textColumn[0] == '(') { // �������� �˻�
		string sentence(textColumn); // sentence = (operator num num)
		char rightPa = sentence.back();
		if (rightPa == ')') { //�� ���� �ݴ� ��ȣ�� �ֳ� Ȯ����
			//cout << ") �� �³� Ȯ�� " << rightPa << endl;
			makeTree(sentence);
			//cout << "���İ˻� �Ϸ� " << sentence << endl;
		}
		else {
			cout << ")�� �������ϴ�. �ùٸ� ������ �ƴմϴ�." << endl;
		}
	}
	else if (textColumn[0] == '-') {
		int i = 1;
		while (*(textColumn + i) != '\0')
		{
			if ('0' <= textColumn[i] && textColumn[i] <= '9') {
				i++;
			}
			else {
				printf("not a valid number : error\n");
				return;
			}
		}
		//num = atoi(textColumn);
		printf("��� : %s\n", textColumn);
	}
	else if ('0' <= textColumn[0] && textColumn[0] <= '9') { // �������� �˻�
		//int num;
		int i = 1;
		while (*(textColumn+i) != '\0')
		{
			if ('0' <= textColumn[i] && textColumn[i] <= '9') {
				i++;
			}
			else {
				printf("not a valid number : error\n");
				return;
			}
		}
		//num = atoi(textColumn);
		printf("��� : %s\n", textColumn);
	}
	else {
		printf("��� : UNDEFINED\n");
		return;
	}
	
}

//bool Token::isStringInt(string token) {
//	int len = token.length();
//	for (int i = 0; i < len; i++)
//	{
//		if (isdigit(token[i])) {
//			cout << token[i] << endl;
//		}
//		else {
//			cout << token[i] <<  "not digit" << endl;
//			return false;
//		}
//	}
//	return true;
//}


void Token::parseInt(string sentence, int i, string* left, string* right) {
	string temp;
	temp = sentence.substr(i);
	//cout << "temp: " << temp << endl;
	int rPa = temp.find(')');
	temp[rPa] = '\0';
	//cout << "temp: " << temp << endl;
	int whiteSpace = temp.find(' ');
	*right = temp.substr(whiteSpace + 1);
	int tempLen = temp.length();
	temp.erase(whiteSpace, tempLen - 1);
	*left = temp;
	//cout << "rightNode : " << *right << "leftNode : " << *left << endl;
	(*right).pop_back();
	//cout << "rightNode : " << *right << "leftNode : " << *left << endl;
}





Token::~Token() { 
	//printf("Token destructor\n"); 
}