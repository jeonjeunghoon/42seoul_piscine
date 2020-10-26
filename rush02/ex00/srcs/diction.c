/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:59:27 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/19 22:58:43 by ywoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int			g_fd;
char		*g_line;

t_dict		*create_ele(char *key, char *val)
{
	t_dict	*ret;

	ret = (t_dict*)malloc(sizeof(t_dict));
	if (safe_dic_guard(ret) == -1)
		return (0);
	ret->key = key;
	ret->value = val;
	ret->next = 0;
	return (ret);
}

void		push_front(char *key, char *val)
{
	t_dict	*tmp;

	if (!g_dict)
	{
		g_dict = create_ele(key, val);
	}
	else
	{
		tmp = g_dict;
		g_dict = create_ele(key, val);
		g_dict->next = tmp;
	}
}

void		insert_key_value(char *str)
{
	char	*key;
	char	*val;
	char	*ptr;

	key = str;
	ptr = str;
	while (*ptr != ':')
		ptr++;
	key = (char*)malloc(ptr - key + 1);
	if (safe_mal_guard(key) == -1)
		return ;
	ft_strcpy(key, str, ptr - 1);
	key = ft_split(key);
	val = ++ptr;
	str = val;
	while (*ptr)
		++ptr;
	val = (char *)malloc(ptr - val + 1);
	if (safe_mal_guard(val) == -1)
		return ;
	ft_strcpy(val, str, ptr - 1);
	val = ft_split(val);
	push_front(key, val);
}

void		build_dict(char *file)
{
	if ((g_fd = open(file, O_RDONLY)) == -1)
	{
		g_open_error = 1;
		print_error_msg("Open error");
		return ;
	}
	while ((g_line = read_line(g_fd)))
	{
		if (g_eof++)
			break ;
		if (!*g_line)
			continue ;
		if (!is_valid_key_value(g_line))
		{
			g_read_error = 1;
			break ;
		}
		insert_key_value(g_line);
	}
	if (g_read_error)
	{
		g_dict_error = 1;
		print_error_msg("Dict Error");
	}
	close(g_fd);
}

char		*get_val(char *key)
{
	t_dict *tmp;

	tmp = g_dict;
	while (tmp)
	{
		if (ft_is_equal(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
