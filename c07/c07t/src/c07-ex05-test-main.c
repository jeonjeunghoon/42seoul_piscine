
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int		is_charset(char c, char *charset);
int		ft_col(char *str, char *charset);
char	**make_split(char *str, char *charset, char **result, int len);
char	**ft_split(char *str, char *charset);

void print_ho(char* src, char* charset)
{
	char **p = ft_split(src, charset);
	int i = -1;
	while(p[++i])
		printf("[%s] ", p[i]);
	printf("\n");
}
int main()
{
		print_ho("; a; b; c; d; e; ", "");
	print_ho("; a; b; c; d; e; ", "; ");
	print_ho("a; b; c; d; e; ", "; ");
	print_ho("; a; b; ; c; d; e", "; ");
	print_ho("; a; b; ; c; d; e. ho. ", ". ");
	print_ho("a; b; c; d; e", "; ");
	print_ho("  \n ", " \n");
}
