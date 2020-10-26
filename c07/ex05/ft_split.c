#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_col(char *str, char *charset)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!*str)
			break ;
		cnt++;
		while (!is_charset(*str, charset) && *str)
			str++;
	}
	return (cnt);
}

char	**make_split(char *str, char *charset, char **result, int len)
{
	int a;
	int b;
	int i;
	char *head;

	a = 0;
	while (len--)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		b = 0;
		i = 0;
		head = str;
		while (!is_charset(*str, charset) && *str)
		{
			str++;
			i++;
		}
		result[a] = (char *)malloc(sizeof(char) * i + 1);
		while (b < i)
		{
			result[a][b] = *head;
			head++;
			b++;
		}
		result[a][b] = 0;
		a++;
	}
	result[a] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int len;
	char **result;

	len = ft_col(str, charset);
	result = (char **)malloc(sizeof(char *) * len + 1);
	result = make_split(str, charset, result, len);
	return (result);
}
