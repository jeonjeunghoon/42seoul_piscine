/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:57:38 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/19 22:47:20 by ywoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char		*ft_split(char *str)
{
	char	*ret;
	char	*begin;
	char	*end;

	if (!*str)
		return (0);
	begin = str;
	while (is_white_space(*begin))
		++begin;
	end = begin;
	while (*end)
		++end;
	--end;
	while (is_white_space(*end))
		--end;
	ret = (char*)malloc(end - begin + 2);
	if (safe_mal_guard(ret) == -1)
		return (0);
	ft_strcpy(ret, begin, end);
	free(str);
	return (ret);
}
