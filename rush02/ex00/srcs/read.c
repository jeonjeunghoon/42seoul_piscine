/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:49:35 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/21 11:12:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char		*read_line(int fd)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(MAX_BUFF + 1);
	if (safe_mal_guard(ret) == -1)
		return (0);
	while ((read(fd, &ret[i], 1)))
	{
		g_eof = 0;
		if (i == MAX_BUFF)
		{
			free(ret);
			g_read_error = 1;
			print_error_msg("Error");
			return (0);
		}
		if (ret[i] == '\n')
		{
			ret[i] = 0;
			break ;
		}
		++i;
	}
	return (ret);
}

void		check_key(void)
{
	t_dict	*tmp1;
	t_dict	*tmp2;
	int		i;

	i = 0;
	tmp1 = g_dict;
	while (tmp1 != 0 && ++i)
	{
		tmp2 = tmp1->next;
		while (tmp2 != 0)
		{
			if (ft_is_equal(tmp1->key, tmp2->key))
			{
				g_dict_error = 1;
				print_error_msg("Dict Error");
				return ;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	dict_error(i);
}

void		dict_error(int i)
{
	if (i < VALID_MIN_DICT)
	{
		g_dict_error = 1;
		print_error_msg("Dict Error");
	}
}

int			all_space(char *str)
{
	int		count;
	int		idx;

	count = 0;
	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13)))
			count++;
		idx++;
	}
	if (count == 0)
	{
		print_error_msg("Error");
		return (0);
	}
	return (1);
}
