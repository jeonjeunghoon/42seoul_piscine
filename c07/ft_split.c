/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:11:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/24 08:02:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int			ft_col(char *str, char *charset)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!*str)
			break ;
		count++;
		while (!is_charset(*str, charset) && *str)
			str++;
	}
	return (count);
}

char		**make_arr_size(char *str, char *charset, char **result, int i)
{
	int		len;
	int		a;
	int		b;
	char	*head;

	a = 0;
	while (i--)
	{
		len = 0;
		b = -1;
		while (is_charset(*str, charset))
			str++;
		head = str;
		while (!is_charset(*str, charset) && *str)
		{
			len++;
			str++;
		}
		result[a] = (char *)malloc(sizeof(char) * len + 1);
		while (++b < len)
			result[a][b] = *head++;
		result[a++][b] = 0;
	}
	result[a] = 0;
	return (result);
}

char		**ft_split(char *str, char *charset)
{
	char	**result;
	int		len;

	len = ft_col(str, charset);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	if (!(result = make_arr_size(str, charset, result, len)))
		return (NULL);
	return (result);
}
