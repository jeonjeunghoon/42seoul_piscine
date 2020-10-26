/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:55:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/24 07:49:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					is_valid(char *base)
{
	int				len;
	int				check[256];
	int				i;
	unsigned char	c;

	i = -1;
	while (++i < 256)
		check[i] = 0;
	len = 0;
	while (base[len])
	{
		c = base[len];
		if ((c == ' ' || (c >= 9 && c <= 13))
				|| check[(int)c] || c == '-' || c == '+')
			return (0);
		check[(int)c] = 1;
		len++;
	}
	if (len <= 1)
		return (0);
	return (len);
}

int					make_digit(char *str, char *base, int len)
{
	int				res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		i = -1;
		while (++i < len)
			if (*str == base[i])
				break ;
		if (i == len)
			break ;
		res = res * len + i;
		str++;
	}
	return (res * sign);
}

int					make_digit_len(int digit, int len)
{
	int				res;

	if (!digit)
		return (0);
	res = digit < 0 ? 1 : 0;
	while (digit)
	{
		digit /= len;
		res++;
	}
	return (res);
}

char				*ft_itoa(int digit, char *base, int len)
{
	char			*res;
	int				size;

	if (!(size = make_digit_len(digit, len)))
	{
		res = (char*)malloc(sizeof(char) * 2);
		res[0] = base[0];
		res[1] = 0;
		return (res);
	}
	res = (char*)malloc(sizeof(char) * (size + 1));
	digit < 0 ? res[0] = '-' : 0;
	digit = digit < 0 ? -digit : digit;
	res[size] = 0;
	while (digit)
	{
		res[--size] = base[digit % len];
		digit /= len;
	}
	return (res);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				digit;
	int				len_from;
	int				len_to;

	len_from = is_valid(base_from);
	len_to = is_valid(base_to);
	if (!len_from || !len_to)
		return (0);
	digit = make_digit(nbr, base_from, len_from);
	return (ft_itoa(digit, base_to, len_to));
}
