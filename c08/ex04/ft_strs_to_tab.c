/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:37:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 19:53:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int					len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char					*ft_strcpy(char *src)
{
	int					i;
	char				*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	t_stock_str			*result;

	i = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (0);
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strcpy(av[i]);
		i++;
	}
	result[i].str = 0;
	result[i].copy = 0;
	result[i].size = 0;
	return (result);
}
