/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:32:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/20 11:21:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			size(char *src)
{
	int		len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char		*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = -1;
	len = size(src);
	dest = (char *)malloc(sizeof(char) * len + 1);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
