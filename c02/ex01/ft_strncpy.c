/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:10:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/09 13:13:17 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*p;

	p = dest;
	while (*src != '\0' && p - dest < n)
	{
		*p = *src;
		p++;
		src++;
	}
	while (p - dest < n)
	{
		*p++ = '\0';
	}
	return (dest);
}
