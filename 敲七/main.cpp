#include <stdio.h>
#define MAX_NUM 30000

bool func(char s[], int c)
{
	int i = 0, num = s[0] - '0';
	if(s[0] == '7')
		return true;
	for(i = 1; i < c; ++i)
	{
		if(s[i] == '7')
			return true;
		num += (s[i] - '0') * 10;
	}
	if(0 == num % 7)
		return true;
	return false;
}
int main(void)
{
	int i = 7, j = 0, num = 0, count = 0;
	char str[5] = { 0 };
	printf("ÇëÊäÈëÊý×Ö£º");
	scanf("%d", &num);
	if(MAX_NUM < i)
	{
		printf("³¬³ö·¶Î§£¡");
		return 0;
	}
	while(i <= num)
	{
		count = 0;
		j = i;
		do
		{
			str[count++] = j % 10 + '0';
			j /= 10;
		}while(j);
		if(func(str, count))
		{
			while(count)
				printf("%c", str[--count]);
			printf("\n");
		}
		++i;
	}
	return 0;
}