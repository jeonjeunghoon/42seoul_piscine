/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:25:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/16 17:30:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char str)
{
	if (str == ' ' || str == '\n' || str == '\t' || str == '\v')
		return (1);
	else if (str == '\f' || str == '\r')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}
