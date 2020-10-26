/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:14:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/09 21:04:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_len(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int dest_len;
	unsigned int result;

	dest_len = get_len(dest);
	result = get_len(src);
	i = 0;
	j = dest_len;
	if (dest_len >= size)
		return (result += size);
	while ((src[i] != '\0') && (i < size - dest_len - 1))
	{
		dest[j++] = src[i++];
	}
	dest[j] = '\0';
	if (size < dest_len)
		result += size;
	else
		result += dest_len;
	return (result);
}
