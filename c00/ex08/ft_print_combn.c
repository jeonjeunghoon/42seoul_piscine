/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:50:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/06 17:50:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_arr[10] = { 0 };

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int pre, int curr, int length)
{
	int i;

	i = -1;
	if (curr == length)
	{
		while (++i < length)
			ft_putchar(g_arr[i] + 48);
		if (g_arr[0] != 10 - length)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	else
	{
		i = pre;
		while (++i <= 9)
		{
			g_arr[curr] = i;
			display(i, curr + 1, length);
		}
	}
}

void	ft_print_combn(int n)
{
	display(-1, 0, n);
}
