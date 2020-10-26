/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:42:17 by yeonkim           #+#    #+#             */
/*   Updated: 2020/07/12 21:44:55 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

int	**g_map;
int	*g_input;
int g_size;
int	g_end = 0;

void	print(void)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i <= g_size)
	{
		j = 1;
		while (j <= g_size)
		{
			c = g_map[i][j] + '0';
			write(1, &c, 1);
			if (j < g_size)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		is_used(int r, int c, int n)
{
	int	check;
	int	nr;
	int	nc;

	check = 1;
	nr = r;
	while (nr > 0)
		if (g_map[--nr][c] == n)
			check = 0;
	nc = c;
	while (nc > 0)
		if (g_map[r][--nc] == n)
			check = 0;
	return (check);
}

void	validate_result(void)
{
	if (!start_check(g_map, g_input))
		return ;
	g_end = 1;
	print();
}

void	dfs(int r, int c, int n)
{
	if (g_end)
		return ;
	if (r == g_size && c == g_size)
	{
		g_map[r][c] = n;
		validate_result();
		return ;
	}
	g_map[r][c] = n;
	if (c == g_size)
	{
		r++;
		c = 1;
	}
	else
		c++;
	n = 1;
	while (n <= g_size)
	{
		if (is_used(r, c, n))
			dfs(r, c, n);
		n++;
	}
}
