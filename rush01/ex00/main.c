/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:34:16 by yeonkim           #+#    #+#             */
/*   Updated: 2020/07/12 22:13:19 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int		g_size = 4;
int		**g_map;
int		*g_input;

int		main(int argc, char **argv)
{
	g_input = malloc(sizeof(int) * g_size * 4);
	if (!check_error(argc, argv))
		return (0);
	solve();
	return (0);
}
