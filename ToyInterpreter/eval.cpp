#include "eval.h"

void evaluate(Stack numbers, Stack ops) {
	if (numbers.IsEmpty())
	{
		printf("empty\n");
		return;
	}
	if (ops.IsEmpty()) {
		printf("empty\n");
		return;
	}
	//ops.view();
	string op = ops.pop();
	//cout << "op : " << op << endl;
	string b = numbers.pop();
	//cout << "b : " << b << endl;
	int bb = stoi(b);
	//cout << "bb : " << bb << endl;
	string a = numbers.pop();
	//cout << "a : " << a << endl;
	int aa = stoi(a);
	//cout << "aa : " << aa << endl;
	if (op == "MINUS")
	{
		int res = aa - bb;
		printf("��� : %d\n", res);
		
	}
	else if (op == "IF") {
		int res;
		if (aa > 0)
		{
			res = bb;
		}
		else {
			res = 0;
		}
		printf("��� : %d\n", res);
	}
	else {
		printf("���̳ʽ��� ������ �ƴ�\n");
		return;
	}
}

