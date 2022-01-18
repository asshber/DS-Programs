#include<iostream>
using namespace std;
template<typename T>
class Stack
{
	T* stack;
	int size;
	int top;
public:
	Stack(int x) :size(x)
	{
		top = -1;
		stack = new T[size];
	}
	void push(T x)
	{
		if (top >= size - 1)
		{
			cout << "Stackover Flow!";
			return;
		}
		else
		{
			top++;
			stack[top] = x;
		}
	}
	T pop()
	{
		if (top <= -1)
		{
			cout << "Stack Underflow!";
			exit(0);
		}
		else
		{
			T temp;
			temp = stack[top];
			top--;
			return temp;
		}
	}
	bool isEmpty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
	bool isFull()
	{
		if (top == size - 1)
			return 1;
		else
			return 0;
	}
	void display()
	{
		for (int i = 0; i < top+1; i++)
			cout << stack[i] << endl;
	}
	T peek()
	{
		return stack[top];
	}
	int pre(char x) {
		if (x == '^')
			return 3;
		else if (x == '/' || x == '*')
			return 2;
		else if (x == '+' || x == '-')
			return 1;
		else
			return -1;
	}
	void postfix(string eq)
	{
		string res;
		for (int i = 0; i < eq.length(); i++)
		{
			char c = eq[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9))
			{
				res += c;
			}
			else if (c == '(')
			{
				push('(');
			}
			else if (c == ')')
			{
				while (peek() != '(')
				{
					res += peek();
					pop();
				}
				pop();
			}
			else
			{
				while (!isEmpty() && pre(eq[i]) <= pre(peek()))
				{
					res += peek();
					pop();
				}
				push(c);
			}
		}
		while (!isEmpty())
		{
			res += peek();
			pop();
		}
		cout << res;
	}
};
int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	int len = exp.length();
	Stack<char> s(len);
	s.postfix(exp);

	return 0;
}