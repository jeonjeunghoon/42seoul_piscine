/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:53:35 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/19 22:44:56 by ywoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_list(t_dict *head)
{
	t_dict *temp;
	t_dict *current;

	temp = head;
	while (temp != 0)
	{
		current = temp->next;
		if (temp == 0)
			break ;
		free(temp->key);
		free(temp->value);
		free(temp);
		temp = 0;
		temp = current;
	}
	free(g_num);
	g_num = 0;
	free(g_line);
	g_line = 0;
	return ;
}

int		safe_dic_guard(t_dict *dic)
{
	if (dic == 0)
	{
		print_error_msg("Malloc allocation error");
		free(dic);
		return (-1);
	}
	return (0);
}

int		safe_mal_guard(char *str)
{
	if (str == 0)
	{
		print_error_msg("Malloc Allocation error");
		free(str);
		return (-1);
	}
	return (0);
}
