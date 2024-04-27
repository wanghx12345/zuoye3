#include<iostream>
#include<stdio.h>
using namespace std;
struct zhan
{
	char* top;
	char* base;
	int size;
	int usingsize;
};
void init_stack(zhan& s)
{
	s.base = (char*)malloc(sizeof(char) * 20);
	s.top = s.base;
	s.size = 20;
	s.usingsize = 0;
}
void push(zhan& s, char e)
{
	if (s.top - s.base >= s.size) {
		char* p;
		p = (char*)realloc(s.base, sizeof(char) * (s.size + 30));
		s.base = p;
		s.top = s.base + s.size;
		s.size += 30;
	}
	*s.top = e;
	s.top++;
}
char pop(zhan& s)
{
	if (s.top == s.base)
	{
		return -1;
	}
	else
	{
		s.top--;
		return *s.top;
	}
}
int main()
{
	printf("��ӭʹ���Զ�����ƥ����\n\n");
	printf("��������Ҫ�жϵı��ʽ\n");
	zhan s;
	int i = 0;
	char e;
	init_stack(s);
	do
	{
		e = getchar();
		if (e == '(' || e == '[' || e == '{')
			push(s, e);
		if (e == ')')
		{
			if (pop(s) != '(')
			{
				i++;
				break;
			}
		}
		if (e == ']')
		{
			if (pop(s) != '[')
			{
				i++;
				break;
			}
		}
		if (e == '}')
		{
			if (pop(s) != '{')
			{
				i++;
				break;
			}
		}

	} while (e != '\n');
	if (i == 0)
	{
		printf("����������ʽ������ƥ����ȷ\n");
	}
	else
		printf("����������ʽ������ƥ�䲻��ȷ\n");
	printf("��ӭ�´�ʹ��");
	system("pause");
	return 0;

}



























































