/**
一个简单的行编辑程序的功能是：接受用户从终端输入的程序或数据，并存入用户的数据区。

由于用户在终端上进行输入时，不能保证不出差错，因此，若在编辑程序中，“每接受一个字符即存入用户数据区”的做法显然不是最恰当的。较好的做法是，设立一个输入缓冲区，用以接受用户输入的一行字符，然后逐行存入用户数据区。允许用户输入出差错，并在发现有误时可以及时更正。例如，当用户发现刚刚键入的一个字符是错的时，可补进一个退格符"#"，以表示前一个字符无效；

如果发现当前键入的行内差错较多或难以补救，则可以键入一个退行符"@"，以表示当前行中的字符均无效。

如果已经在行首继续输入'#'符号无效。

Input
输入一个多行的字符序列。但行字符总数（包含退格符和退行符）不大于250。

Output
按照上述说明得到的输出。

Sample Input
whli##ilr#e(s#*s)
outcha@putchar(*s=#++);

Sample Output
while(*s)
putchar(*s++);
*/

#include <stdio.h>
#define BUFFER_SIZE 20

void Edit()
{
	char buf[BUFFER_SIZE] = { 0 };
	int count = 0, i = 0;
	char c = 0;
	do
	{
		c = getchar();
		if('#' == c)
		{
			if(0 != count)
			{
				--count;
			}
		}
		else if('@' == c)
		{
			count = 0;
		}
		else
		{
			buf[count++] = c;
		}
		if(BUFFER_SIZE == count)
		{
			for(i = 0; --count; ++i)
			{
				printf("%c", buf[i]);
			}
		}
	}while(c != '\n');

	for(i = 0; i < count; ++i)
	{
		printf("%c", buf[i]);
	}
}
int main(void)
{
	printf("请输入：\n");
	Edit();
	return 0;
}