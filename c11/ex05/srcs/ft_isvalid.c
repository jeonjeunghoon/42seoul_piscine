#include "ft_boolean.h"

int		is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' ||
			c == '\r' || c == '\v');
}
