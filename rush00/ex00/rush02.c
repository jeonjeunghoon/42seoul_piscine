/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:32:28 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/04 17:06:56 by jeunjeon         ###   ########.fr       */
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
			if (j == 1 && (i == 1 || i == x))
				ft_putchar('A');
			else if (j == y && (i == 1 || i == x))
				ft_putchar('C');
			else if (i > 1 && i < x && j > 1 && j < y)
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		ft_putchar('\n');
	}
}
