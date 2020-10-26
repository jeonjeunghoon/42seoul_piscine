/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:16:56 by yeonkim           #+#    #+#             */
/*   Updated: 2020/07/12 22:07:22 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush01.h"

int		**g_map;
int		*g_input;
int		g_size;
int		g_end;

void	solve(void)
{
	int	i;

	g_map = malloc_map(g_size + 1);
	i = 1;
	while (i <= g_size)
		dfs(1, 1, i++);
	if (!g_end)
	{
		write(1, "Error\n", 6);
	}
	free_map(g_map, g_size);
}
