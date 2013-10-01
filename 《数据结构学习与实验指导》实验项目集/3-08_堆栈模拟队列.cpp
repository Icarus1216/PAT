#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

class stack
{
public:
	/*ջ��С*/
	int len; 
	/*ջԪ��*/
	int *elem;
	/*ջָ��*/ 
	int pt;
	/*��ʼ��ջ*/
	stack(int n);		 
	/*�ж�ջ�Ƿ���*/
	int IsFull();	
	/*�ж�ջ�Ƿ�Ϊ��*/ 
	int IsEmpty();
	/*Ԫ��ѹջ*/
	void Push(int item);
	/*ջԪ�ص���*/
	int Pop();
	/*ջԪ�ظ���*/
	int Size(); 
}; 

stack::stack(int n)
{
	elem = new int[n+1];
	pt = 0;	
	len = n;
}

int stack::IsFull()
{
	if(pt == len)
		return 1;
	else	
		return 0;		
}

int stack::IsEmpty()
{
	if(pt == 0)
		return 1;
	else
		return 0;
}

void stack::Push(int item)
{
	if(!IsFull())
	{
		pt++;
		elem[pt] = item;
	}
	else
	{
		cout << "ERROR:Full" << endl;
	}
}

int stack::Pop()
{
	if(!IsEmpty())
	{
		int item = elem[pt];
		pt--;
		return item;
	}
	else
	{
		cout << "ERROR:Empty" << endl;
	}
}

int stack::Size()
{
	return pt;
}

class queue
{
public:
	stack s1,s2;
	/*��ʼ������*/ 
	queue(int n1, int n2):s1(n1),s2(n2){}
	/*��Ӳ���*/
	void AddQ(int item);
	/*���Ӳ���*/
	int DeleteQ();
};

void queue::AddQ(int item)
{
	if( (s1.Size() < min(s1.len,s2.len)) )
	{
		s1.Push(item);
	}
	else if(s1.Size() == min(s1.len,s2.len) && s2.IsEmpty() )
	{		
		while(!s1.IsEmpty())
		{
			s2.Push(s1.Pop());
		}
		s1.Push(item);
	}
	else if(s1.Size() == min(s1.len,s2.len) && !s2.IsEmpty())
	{
		cout << "ERROR:Full" << endl;
	}
}

int queue::DeleteQ()
{
	if(!s2.IsEmpty())
	{
		cout << s2.Pop() << endl;
	}
	else
	{
		while(!s1.IsEmpty() && !s2.IsFull())	
		{
			s2.Push(s1.Pop());	
		}
		if( s2.IsEmpty() )
		{
			cout << "ERROR:Empty" << endl;
		}
		else
		{
			cout << s2.Pop() << endl;
		}	
	}
}

int Convert(string tmp)
{
	int i;
	char *str = new char[tmp.size()];
	for(i = 0; i < tmp.size(); i++)
		str[i] = tmp[i];
	int res;
	sscanf(str, "%d", &res);
	return res;
}

int main()
{
	int n1,n2,i;
	string ins;
	cin >> n1 >> n2;
	getchar();
	queue q(n1,n2);
	getline(cin, ins);
	string tmp = "";
	for(i = 0; i < ins.size(); i++)
	{
		if(ins[i] == ' ')
		{
			if(tmp == "A")
			{
				tmp = "";
				i++;
				while(ins[i] != ' ')
				{
					tmp += ins[i];
					i++;
				}	
				q.AddQ(Convert(tmp));	
			}
			else if(tmp == "D")
			{
				q.DeleteQ();	
			}
			tmp = "";
		}
		else	tmp += ins[i];
	}
	return 0;
}