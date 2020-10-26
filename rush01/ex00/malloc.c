/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:40:42 by yeonkim           #+#    #+#             */
/*   Updated: 2020/07/12 18:40:43 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**malloc_map(int size)
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
		map[i++] = malloc(sizeof(int) * size);
	return (map);
}

void	free_map(int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
}
