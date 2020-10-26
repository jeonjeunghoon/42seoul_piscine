
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int			ft_ultimate_range(int **range, int min, int max);

int main()
{
		int i = 0;
	int j = 0;
	int* range;
	j = ft_ultimate_range(&range, 0, 10);
	printf("ft_ultimate_range(&range, 0, 10) >> ");
	for(i = 0;i<10;i++)
	{
		printf("%d ", range[i]);
	}
	printf(" num:%d\n", j);
	i = ft_ultimate_range(&range, 30, 10);
	printf("ft_ultimate_range(&range, 30, 10) >> num:%d, memory: %ld\n", i, (long)range);
	i = ft_ultimate_range(&range, 6, 6);
	printf("ft_ultimate_range(&range, 6, 6) >> num:%d, memory: %ld\n",i,  (long)range);
	j = ft_ultimate_range(&range, 6, 7);
	printf("ft_ultimate_range(&range, 6, 7) >> ");
	for(i = 0; i < 1; i++)
	{
		printf("%d ", range[i]);
	}
	printf(" num:%d\n", j);
		j = ft_ultimate_range(&range, -2, 5);
	printf("ft_ultimate_range(&range, -2, 5) >> ");
	for(i = 0; i < 7; i++)
	{
		printf("%d ", range[i]);
	}
	printf(" num:%d\n", j);
}
