#ifndef __Formula_H__
#define __Formula_H__

#include <iostream>
#include <vector>
#include <map>
#include "Stack.h"

using namespace std;

class TFormula
{
private:
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<char, double> operands;

	void Parse();
	void ToPostfix();

public:
	TFormula(string infix);
	string GetInfix() const;
	string GetPostfix() const;

	vector<char> GetOperands() const;
	double Calculate(const map<char, double>& values);
};
#endif


inline void TFormula::Parse()
{
	for (char c : infix)
		if ((c == '!') || (c == '@') || (c == '_') || (c == '&') || (c == '~') || (c == '$') || (c == '?') || (c == ':'))
		{
			throw "Error";
		}
		else
			lexems.push_back(c);
}

inline void TFormula::ToPostfix()
{
	Parse();
	TStack<char> st;
	char stackItem;
	for (char item : lexems)
	{
		switch (item)
		{
		case '(':
			st.Push(item);
			break;
		case ')':
			stackItem = st.Pop();
			while (stackItem != '(')
			{
				postfix += stackItem;
				stackItem = st.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!st.IsEmpty())
			{
				stackItem = st.Pop();
				if (priority[item] <= priority[stackItem])
					postfix += stackItem;
				else
				{
					st.Push(stackItem);
					break;
				}
			}
			st.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
		}
	}
	while (!st.IsEmpty())
	{
		stackItem = st.Pop();
		postfix += stackItem;
	}
}

inline TFormula::TFormula(string infix) : infix(infix)
{
	priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
	ToPostfix();
}

inline string TFormula::GetInfix() const
{
	return infix;
}

inline string TFormula::GetPostfix() const
{
	return postfix;
}

inline vector<char> TFormula::GetOperands() const
{
	vector<char> op;
	for (const auto& item : operands)
		op.push_back(item.first);
	return op;
}

inline double TFormula::Calculate(const map<char, double>& values)
{
	for (auto& val : values)
	{
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
	TStack<double> st;
	double leftOperand, rightOperand;
	for (char lexem : postfix)
	{
		switch (lexem)
		{
		case '+':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			if (rightOperand == 0)
			{	
				throw "Error";
			}
			else
			{
				st.Push(leftOperand / rightOperand);
				break;
		default:
			st.Push(operands[lexem]);
			}
		}
	}
	return st.Pop();
}
