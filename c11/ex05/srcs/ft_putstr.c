#include <unistd.h>

#include "ft_io.h"
#include "ft_char.h"

void	ft_putstr_to(int fd, char *str)
{
	while (*str)
	{
		ft_putchar_to(fd, *str);
		str++;
	}
}

void	ft_putstr(char *str)
{
	ft_putstr_to(OUT, str);
}
