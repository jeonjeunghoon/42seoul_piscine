/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:58:26 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/19 06:57:48 by ywoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	print_error_msg(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
}

void	print(char *str)
{
	if (g_is_first)
		ft_putstr(" ");
	g_is_first = 1;
	ft_putstr(str);
}
