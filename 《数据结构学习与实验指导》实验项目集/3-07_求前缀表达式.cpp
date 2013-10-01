#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*
ǰ׺���ʽ��ֵ��ͨ������ջ������ջ����������������㡣 
1.������ջ
2.������ջ
3.IF ����ջ >= 2 && ����ջ >= 1
	��������A,B ����op
	�������� C = A op B 
	��Cѹ������ջ
   	ֱ������ջ ��С Ϊ  1
4.ע�����������ж� 
*/
stack<char> 	opStack;
stack<double> 	valStack;

double Convert(string str)
{
	int i,j;
	double val;
	char valChar[50];
	for(i = str.size()-1,j = 0; i >= 0; i--, j++)
		valChar[j] = str[i];
	sscanf(valChar, "%lf", &val);
	return val;
} 

void Work(string str)
{
	int i,Error = 0;
	string tmp = "";
	for(i = str.size()-1; i >= 0; i--)
	{
		if(str[i] == ' ')
		{
			if(tmp == "+")		opStack.push('+');
			else if(tmp == "-")	opStack.push('-');	
			else if(tmp == "*")	opStack.push('*');
			else if(tmp == "/")	opStack.push('/');
			else				valStack.push(Convert(tmp));	
			tmp = "";
			while(valStack.size() >= 2 && opStack.size() >= 1)
			{//�������� 
				double a = valStack.top(); valStack.pop();
				double b = valStack.top(); valStack.pop();
				char op  = opStack.top();  opStack.pop();
				if(op == '+')	 	valStack.push(a+b);
				else if(op == '-') 	valStack.push(a-b);
				else if(op == '*') 	valStack.push(a*b);
				else if(op == '/')
				{
					if(b==0) 
					{
						Error = 1;
						break;
					}
					else valStack.push(a/b);
				} 	
			}
		}	
		else
		{
			tmp += str[i];
		}
	}
	
	if(Error == 1)
	{
		puts("ERROR"); return;
	}
	
	if(tmp == "+")		opStack.push('+');
	else if(tmp == "-")	opStack.push('-');	
	else if(tmp == "*")	opStack.push('*');
	else if(tmp == "/")	opStack.push('/');
	else				valStack.push(Convert(tmp));	
	tmp = "";
	while(valStack.size() >= 2 && opStack.size() >= 1)
	{//�������� 
		double a = valStack.top(); valStack.pop();
		double b = valStack.top(); valStack.pop();
		char op  = opStack.top();  opStack.pop();
		if(op == '+')	 	valStack.push(a+b);
		else if(op == '-') 	valStack.push(a-b);
		else if(op == '*') 	valStack.push(a*b);
		else if(op == '/')
		{
			if(b==0) 
			{
				Error = 1;
				break;
			}
			else valStack.push(a/b);
		}
	}
	
	if(Error == 1)
	{
		puts("ERROR"); return;
	}
	
	if(opStack.size() == 0 && valStack.size() == 1)
	{
		printf("%.1lf\n", valStack.top());
	}
	else
	{
		puts("ERROR");
	}
}

int main()
{
	string str;
	getline(cin, str);
	Work(str);
	system("pause");
	return 0;
} 