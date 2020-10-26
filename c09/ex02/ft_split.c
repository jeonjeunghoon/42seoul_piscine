/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:29:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 17:32:51 by jeunjeon         ###   ########.fr       */
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
	int		cnt;

	cnt = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!*str)
			return (cnt);
		cnt++;
		while (!is_charset(*str, charset) && *str)
			str++;
	}
	return (cnt);
}

char		**make_arr_size(char *str, char *charset, char **result, int len)
{
	int		a;
	int		b;
	int		row_len;
	char	*head;

	a = 0;
	while (len--)
	{
		b = 0;
		row_len = 0;
		while (is_charset(*str, charset) && *str)
			str++;
		head = str;
		while (!is_charset(*str, charset) && *str)
		{
			str++;
			row_len++;
		}
		result[a] = (char *)malloc(sizeof(char) * row_len + 1);
		while (b < row_len)
			result[a][b++] = *head++;
		result[a++][b] = 0;
	}
	result[a] = 0;
	return (result);
}

char		**ft_split(char *str, char *charset)
{
	int		col_len;
	char	**result;

	col_len = ft_col(str, charset);
	if (!(result = (char **)malloc(sizeof(char *) * col_len + 1)))
		return (NULL);
	if (!(result = make_arr_size(str, charset, result, col_len)))
		return (NULL);
	return (result);
}
