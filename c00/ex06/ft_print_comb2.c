/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:48:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/20 17:36:49 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_express(int n)
{
	int first_digit;
	int second_digit;

	if (n <= 99)
	{
		first_digit = n / 10;
		second_digit = n % 10;
		ft_putchar(first_digit + 48);
		ft_putchar(second_digit + 48);
	}
	else
	{
		first_digit = 0;
		second_digit = 0;
		ft_putchar(first_digit);
		ft_putchar(second_digit);
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	while (++a < 99)
	{
		b = a;
		while (++b <= 99)
		{
			ft_express(a);
			ft_putchar(' ');
			ft_express(b);
			if (a < 98 || b < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
	ft_putchar('\n');
}
