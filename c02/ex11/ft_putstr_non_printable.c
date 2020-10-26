/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:48:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/20 19:29:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

int					is_printable(char ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	else
		return (0);
}

void				ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	current;

	i = 0;
	while (1)
	{
		current = str[i];
		if (!current)
			break ;
		if (is_printable(current))
			ft_putchar(current);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current / 16]);
			ft_putchar("0123456789abcdef"[current % 16]);
		}
		i++;
	}
}
