/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:43:04 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/20 19:48:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			attach_size(char **strs, char *sep, int size)
{
	int		i;
	int		sum_size;

	i = 0;
	sum_size = 0;
	while (i < size)
	{
		sum_size += ft_strlen(strs[i]);
		sum_size += ft_strlen(sep);
		i++;
	}
	sum_size -= ft_strlen(sep);
	return (sum_size);
}

char		*make_arr(int size, char **strs, char *sep, char *arr)
{
	int		i;
	char	*read;

	read = arr;
	i = 0;
	while (i < size)
	{
		ft_strcpy(read, strs[i]);
		read += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(read, sep);
			read += ft_strlen(sep);
		}
		i++;
	}
	*read = '\0';
	return (arr);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;

	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char));
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * attach_size(strs, sep, size) + 1);
	arr = make_arr(size, strs, sep, arr);
	return (arr);
}
