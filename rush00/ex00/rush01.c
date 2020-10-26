/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:22:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/04 17:08:07 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	j = 0;
	while (++j <= y)
	{
		i = 0;
		while (++i <= x)
		{
			if ((i == 1 && j == 1) || (i == x && j == y))
				ft_putchar('/');
			else if ((i == x && j == 1) || (i == 1 && j == y))
				ft_putchar('\\');
			else if (i > 1 && i < x && j > 1 && j < y)
				ft_putchar(' ');
			else
				ft_putchar('*');
		}
		ft_putchar('\n');
	}
}
