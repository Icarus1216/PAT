#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

/*
��׺ת��׺���ʽ
�㷨˼·:
��׺���ʽa + b*c + (d * e + f) * g����ת���ɺ�׺���ʽ��Ϊa b c * + d e * f  + g * +��
ת��������Ҫ�õ�ջ������������£�
1��������������������Ǿ�ֱ�ӽ��������
2����������������������ǽ�����뵽ջ�У�����������ʱ����Ҳ�������ջ�С�
3���������һ�������ţ���ջԪ�ص������������Ĳ��������ֱ������������Ϊֹ��ע�⣬������ֻ�������������
4����������κ������Ĳ��������� + ��- , * ��\ , ( �ȣ�
��ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ��
��������ЩԪ�غ󣬲Ž������Ĳ�����ѹ�뵽ջ�С�
��һ����Ҫע�⣬ֻ�������� ) ����������ǲŵ��� ( ������������Ƕ����ᵯ�� ( ��
Ҳ����˵���ֲ����� + -�����ȼ����, ( ���ȼ���ߡ�
5��������Ƕ����������ĩβ����ջ������Ԫ�����ε�����

ע������ 
1. ע���ʽĩβû�� �ո���firstPrint������ 
2. ע��-2+(+3)+(-2)��һ������� 
2. ���ȼ���ϵ
3. ���ֺͷ�������ķ���
4. �� = ����ջ�׽��б��� 
*/


//���ȼ��ж� 
int OperPrior(char op)
{
	int key;
	switch(op)
	{
		case '=':
			return 0;
		case '+':
		case '-': 
			return 1; 
		case '*': 
		case '/': 
			return 2; 
		case '(':
		case ')': 
			return 3;
	}
}

void Run() 
{	
	stack<char> optr;			//������ջ
	optr.push('=');				//ѹ��'='��Ϊ����
	char ch;
	double operand;
	int First = 1;
	int LastType;
	int firstPrint = 1;
	ch = getchar();
	while(ch != '\n') 
	{//��ǰ���ʽ��δ�����������������
		if( (ch <= '9' && ch >= '0') || 
			( (ch == '+' || ch == '-') && 
			  ( First || (optr.top() == '(' && LastType == 1) ) ))
		{//chΪ��һ���������ĵ�һ���ַ�
			cin.putback(ch);			//���ַ�ch�Ż�������
			cin >> operand;				//���������
			if(firstPrint)	
			{
				firstPrint = 0;
				cout << operand;
			}
			else	cout << " " << operand;
			First = 0;
			LastType = 0;
			ch = getchar();				//������һ���ַ�
		}
		else 
		{//chΪ������
			LastType = 1;
			if ( ch == ')' )
			{
				while (optr.top() != '(')
				{
					if(firstPrint)	
					{
						firstPrint = 0;
						cout << optr.top();
					}
					else cout << " " << optr.top();
					optr.pop();
				}
				optr.pop();
			}
			else if ( OperPrior(optr.top()) < OperPrior(ch) )
			{
				optr.push(ch);					//ch��optrջ
			}
			else if ( OperPrior(optr.top()) >= OperPrior(ch) )
			{//opreTop���ڻ����ch�����ȼ�
				while(optr.top() != '(' && OperPrior(optr.top()) >= OperPrior(ch))
				{
					if(firstPrint)	
					{
						firstPrint = 0;
						cout << optr.top();
					}
					else	cout << " " << optr.top();
					optr.pop();
				}
				optr.push(ch);
			}
			ch = getchar();//�������ַ�
		}
	}

	while( !optr.empty() ) 
	{
		if(optr.top() == '=')	break;
		if(firstPrint)	
		{
			firstPrint = 0;
			cout << optr.top();
		}
		else	cout << " " << optr.top();
		optr.pop();
	}
	cout << endl; 
}

int main()
{
	Run(); 
	return 0;
}