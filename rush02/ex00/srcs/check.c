/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:55:21 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/19 21:53:25 by ywoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		is_white_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int		ft_is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_is_valid_number(char *str)
{
	check_key();
	if (!str || (*str == '0' && *(str + 1)))
		return (0);
	while (*str)
	{
		if (!ft_is_number(*str))
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_key_value(char *str)
{
	int	cnt_colon;
	int	cnt_key;
	int	cnt_val;

	cnt_colon = 0;
	cnt_key = 0;
	cnt_val = 0;
	if (before_split_error(str) == 0)
		g_read_error = 1;
	while (*str)
	{
		if (*str == ':')
			++cnt_colon;
		else if (!is_white_space(*str))
		{
			if (cnt_colon)
				++cnt_val;
			else
				++cnt_key;
		}
		++str;
	}
	return (cnt_colon >= 1 && cnt_key > 0 && cnt_val > 0);
}

int		check_arg(int argc, char **argv)
{
	if (argc == 2)
	{
		if (all_space(argv[1]) == 0)
			return (0);
		argv[1] = chk_argv_zero(argv[1]);
		build_dict(DEFAULT_FILE);
		if (g_read_error == 1)
			return (0);
		g_num = ft_split(argv[1]);
		return (1);
	}
	else if (argc == 3)
	{
		if (all_space(argv[2]) == 0)
			return (0);
		build_dict(argv[1]);
		argv[2] = chk_argv_zero(argv[2]);
		g_num = ft_split(argv[2]);
		return (1);
	}
	else
	{
		print_error_msg("Error");
		return (0);
	}
}
