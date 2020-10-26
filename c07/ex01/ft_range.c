/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:49:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/19 23:51:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_range(int min, int max)
{
	int		*arr;
	long	i;
	long	len;

	i = 0;
	len = (long)max - (long)min;
	if (max <= min)
	{
		arr = NULL;
	}
	else
	{
		arr = (int *)malloc(sizeof(int) * len);
		while (min < max)
		{
			arr[i] = min;
			min++;
			i++;
		}
	}
	return (arr);
}
