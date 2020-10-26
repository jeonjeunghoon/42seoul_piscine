/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:37:39 by junghlee          #+#    #+#             */
/*   Updated: 2020/07/04 17:29:45 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_set_stat(int x, int y, int i, int j);

char	ft_get_stat_char(int stat);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(ft_get_stat_char(ft_set_stat(x, y, i, j)));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_set_stat(int x, int y, int i, int j)
{
	int stat;

	stat = 0;
	stat |= (i == 0) ? (1 << 0) : 0;
	stat |= (i == y - 1) ? (1 << 1) : 0;
	stat |= (j == 0) ? (1 << 2) : 0;
	stat |= (j == x - 1) ? (1 << 3) : 0;
	return (stat);
}

char	ft_get_stat_char(int stat)
{
	static	char const stat_s[16] = " BBBBACABCACBACA";

	return (stat_s[stat]);
}
