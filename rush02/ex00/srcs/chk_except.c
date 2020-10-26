/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:01:18 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/19 20:57:02 by ywoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int			before_split_error(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] != ':')
		{
			if (is_white_space(str[idx]) || ft_is_number(str[idx]))
				idx++;
			else
				return (0);
		}
		else if (str[idx++] == ':')
			break ;
	}
	while (str[idx])
	{
		if (is_white_space(str[idx]) || (str[idx] >= ' ' && str[idx] <= '~'))
			idx++;
		else
			return (0);
	}
	return (1);
}

char		*chk_argv_zero(char *str)
{
	int		i;
	int		idx_zero;
	char	*tmp;

	if ((tmp = (char *)malloc(2)) == 0)
	{
		free(tmp);
		return (str);
	}
	tmp[0] = '0';
	tmp[1] = 0;
	idx_zero = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '0')
			idx_zero++;
		else
			break ;
	}
	if (idx_zero == ft_strlen(str))
		str = tmp;
	else
		str = make_sig(idx_zero, str);
	return (str);
}

char		*make_sig(int idx_zero, char *str)
{
	char	*tmp;
	char	*begin;
	char	*end;

	begin = &str[idx_zero];
	end = &str[ft_strlen(str) - 1];
	if ((tmp = (char *)malloc(end - begin + 2)) == 0)
	{
		free(tmp);
		return (str);
	}
	ft_strcpy(tmp, begin, end);
	return (tmp);
}
