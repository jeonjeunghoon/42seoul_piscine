/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:51:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/21 12:00:04 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		make_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_valid_base(char *base)
{
	int i;
	int j;
	int len;

	len = make_len(base);
	if (len == 0 || len == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if ((base[i] == base[j]) || base[i] == '-' || base[i] == '+')
				return (0);
			if (base[i] == ' ' || base[i] == '\n' || base[i] == '\t' ||
					base[i] == '\v' || base[i] == '\r' || base[i] == '\f')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		make_digit(char c, char *base)
{
	int len_base;
	int i;

	i = 0;
	len_base = make_len(base);
	while (i < len_base)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int		is_base(char c, char *base)
{
	int i;
	int len_base;

	i = 0;
	len_base = make_len(base);
	while (i < len_base)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int sum;

	i = 0;
	sign = 1;
	sum = 0;
	if (!is_valid_base(base) || make_len(str) == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_base(str[i], base))
	{
		sum = sum * make_len(base) + make_digit(str[i], base);
		i++;
	}
	return (sign * sum);
}
