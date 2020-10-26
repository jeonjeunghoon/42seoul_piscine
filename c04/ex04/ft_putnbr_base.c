/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 22:43:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/18 22:43:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			len_base(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			is_valid_base(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((str[i] == str[j]) || str[i] == '+' || str[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			len_of_arr(int nbr, int base_len)
{
	int		i;

	i = 0;
	while (nbr /= base_len)
		i++;
	return (i);
}

void		digits_to_base(int nbr, char *base, int base_len, int last_index)
{
	char	result_arr[50];
	int		i;
	int		j;

	i = 0;
	j = last_index;
	while (last_index >= 0)
	{
		if (nbr > 0)
		{
			result_arr[last_index] = base[nbr % base_len];
			nbr = -(nbr / base_len);
		}
		else if (nbr < 0)
		{
			result_arr[last_index] = base[-(nbr % base_len)];
			nbr = -(nbr / base_len);
		}
		last_index--;
	}
	while (i <= j)
	{
		write(1, &result_arr[i], 1);
		i++;
	}
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		last_index;

	base_len = len_base(base);
	if (!is_valid_base(base) || base_len == 0 || base_len == 1)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	last_index = len_of_arr(nbr, base_len);
	if (nbr < 0)
		write(1, "-", 1);
	digits_to_base(nbr, base, base_len, last_index);
}
