#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

/*
Copy�������еĴ�������޸ĵõ�
�������������Ĳ���Ҫ��ʣ�µĶ����һ��
*/

double number[4];
string result[4];

bool PointsGame(int n)
{
    if(n == 1)
    {
        if(fabs(number[0] - 24.0) < 1e-12)
        {
            cout << result[0] << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            double a, b;
            string expa, expb;

            a = number[i];
            b = number[j];
            number[j] = number[n-1];     //��ȡ�����������������������ԭ����ĸ�������һ��

            expa = result[i];            //������ʽ�е�����
            expb = result[j];
            result[j] = result[n-1];

            if(n != 2)
                result[i] = '(' + expa + '+' + expb + ')';      //��ȡ���������ڡ�+��������µĽ��
            else
                result[i] = expa + '+' + expb;
            number[i] = a + b;                              //����������µ�����������������
            if(PointsGame(n - 1))
                return true;

            if(n != 2)
                result[i] = '(' + expa + '-' + expb + ')';      //��ȡ���������ڡ�-��������µĽ��
            else
                result[i] = expa + '-' + expb;
            number[i] = a - b;
            if(PointsGame(n - 1))
                return true;

            if(n != 2)
                result[i] = '(' + expb + '-' + expa + ')';      //��ȡ���������ڡ�-��������µĽ��
            else
                result[i] = expb + '-' + expa;
            number[i] = b - a;
            if(PointsGame(n - 1))
                return true;

            if(n != 2)
                result[i] = '(' + expa + '*' + expb + ')';      //��ȡ���������ڡ�*��������µĽ��
            else
                result[i] = expa + '*' + expb;
            number[i] = a * b;
            if(PointsGame(n - 1))
                return true;
            if(b != 0)
            {
                if(n != 2)
                    result[i] = '(' + expa + '/' + expb + ')';  //��ȡ���������ڡ�/��������µĽ��
                else    result[i] = expa + '/' + expb;
                number[i] = a / b;
                if(PointsGame(n - 1))
                    return true;
            }
            if(a != 0)
            {
                if(n != 2)
                    result[i] = '(' + expb + '/' + expa + ')';  //��ȡ���������ڡ�/��������µĽ��
                else
                    result[i] = expb + '/' + expa;
                number[i] = b / a;
                if(PointsGame(n - 1))
                    return true;
            }
            number[i] = a;    //���տ�ʼ��ȡ�����������·Ż������ж�Ӧ��λ��
            number[j] = b;
            result[i] = expa;
            result[j] = expb;
        }
    }
    return false;
}

void itoa(int e,char *buffer)
{
	int i = 0;
	if(!e)	buffer[i++] = 0;
	while(e)
	{
		buffer[i++] = (e%10) + '0';
		e /= 10;
	}
	int len = i;
	for(i = 0; i < len/2; i++)
	{
		char tmp = buffer[i];
		buffer[i] = buffer[len-i-1];
		buffer[len-i-1] = tmp;
	}
	buffer[len] = '\0';
}

int main()
{
    int i,e;
    for(i = 0; i < 4; i++)
    {
        char buffer[20];
        cin >> e;
        number[i] = e;
        itoa(e, buffer);
        result[i] = buffer;
    }
    if(!PointsGame(4))
    {
        cout << "-1" << endl;
    }
    return 0;
}
