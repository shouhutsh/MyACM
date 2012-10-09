#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int m_div;
	int m_rem;
}Node;

void Sort(Node *Array, int size)
{
	int i = 0, j = 0;
	Node temp;
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size - i; ++j)
		{
			if(Array[j].m_div < Array[j+1].m_div)
			{
				temp.m_div = Array[j].m_div;
				temp.m_rem = Array[j].m_rem;

				Array[j].m_div = Array[j+1].m_div;
				Array[j].m_rem = Array[j+1].m_rem;

				Array[j+1].m_div = temp.m_div;
				Array[j+1].m_rem = temp.m_rem;
			}
		}
	}
}

union NO(const Node a, const int num)
{
	return ( (num - a.m_rem) % a.m_div );
}

void Action(const Node *Array, const int size)
{
	bool judge = true;
	int i = 0, j = 0, num = 0;
	while(true)
	{
		++i;
		judge = true;
		num = Array[0].m_div * i + Array[0].m_rem;
		for(j = 1; j < size; ++j)
		{
			if( NO(Array[j], num) )
			{
				judge = false;
				break;
			}
		}
		if(judge)
		{
			printf("\n%d\n", num);
			return ;
		}
	}
}
int main(void)
{
	int i= 0, size = 0, num = 0;

	scanf("%d", &size);
	Node *Array = (Node*) malloc(sizeof(Node) * size);
	while(i < size)
	{
		scanf("%d %d", &Array[i].m_div, &Array[i].m_rem);
		++i;
	}

	Sort(Array, size);

	Action(Array, size);

	return 0;
}