
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int			size(char *src);
char		*ft_strdup(char *src);

int main()
{
		char* p = ft_strdup("Hello World!");
	printf("content: %s\n", p);
	printf("len: %lu\n", strlen(p));
}
