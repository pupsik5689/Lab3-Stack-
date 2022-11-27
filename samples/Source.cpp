#include "Stack.h"
#include <iostream>
#include "Formula.h"
using namespace std;

int main()
{
	TStack<int> a(5);
	a.Push(1);
	a.Push(2);
	a.Push(3);
	a.Push(4);
	a.Push(5);

	for (int i = 0; i < 5; i++)
		std::cout << a.Pop();
	std::cout << endl;

	string exprStr;
	cout << "Enter expr :";
	cin >> exprStr;
	//exprStr = "(a+b*c/d-e)*(a+b)";
	TFormula expr(exprStr);
	cout << expr.GetInfix() << endl;
	cout << expr.GetPostfix() << endl;
	vector<char> operands = expr.GetOperands();
	map<char, double> values;
	double val;
	for (const auto& op : operands)
	{
		cout << "Enter values of " << op << ": ";
		cin >> val;
		values[op] = val;
	}
	cout << expr.Calculate(values) << endl;
	setlocale(LC_ALL, "Russian");
}