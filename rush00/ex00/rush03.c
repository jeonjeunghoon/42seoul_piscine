/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosong <mosong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:40:27 by mosong            #+#    #+#             */
/*   Updated: 2020/07/05 15:24:41 by mosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		rush(int x, int y)
{
	char	lefttopv;
	int		r;
	int		c;

	lefttopv = 'A';
	r = 0;
	c = 0;
	while (++r <= y)
	{
		while (++c <= x)
		{
			if ((c == 1 && r == 1) || (c == 1 && r == y))
				ft_putchar(lefttopv);
			else if ((c == x && r == 1) || (c == x && r == y))
				ft_putchar(lefttopv + 2);
			else if (c == 1 || c == x || r == 1 || r == y)
				ft_putchar(lefttopv + 1);
			else
				ft_putchar(lefttopv - 33);
		}
		ft_putchar('\n');
		c = 0;
	}
}
