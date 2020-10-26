
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int			*ft_range(int min, int max);

void print_range(int* range, int len)
{
	int i;
	if (len == 0)
	{
		printf("if 0, it is nullptr >> %ld\n", (long)range);
		return;
	}

	for(i = 0;i<len;i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");
}
int main()
{
		int i = 0;
	int* range = ft_range(0, 10);
	printf("ft_range(0, 10) >> ");
	for(i = 0;i<10;i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");
	printf("ft_range(30, 10) >> ");
	print_range(ft_range(30, 10), 0);
	printf("ft_range(6, 9) >> ");
	print_range(ft_range(6, 9), 3);
	printf("ft_range(-2, 10) >> ");
	print_range(ft_range(-2, 10), 11);
}
