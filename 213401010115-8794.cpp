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
	printf("欢迎使用自动括号匹配器\n\n");
	printf("请输入需要判断的表达式\n");
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
		printf("这个算术表达式的括号匹配正确\n");
	}
	else
		printf("这个算术表达式的括号匹配不正确\n");
	printf("欢迎下次使用");
	system("pause");
	return 0;

}



























































