/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:37:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/13 12:59:04 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *s1;
	char *ptr;

	if (*to_find == '\0')
		return (str);
	s1 = str;
	ptr = to_find;
	while (1)
	{
		if (*ptr == '\0')
			return (s1 - (ptr - to_find));
		if (*s1 == *ptr)
			ptr++;
		else
			ptr = to_find;
		if (*s1 == '\0')
			break ;
		s1++;
	}
	return (0);
}
