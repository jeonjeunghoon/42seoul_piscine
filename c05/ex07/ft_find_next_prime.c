/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:15:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/16 18:27:50 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_prime(int nb, int x)
{
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (x <= nb / 2)
	{
		if (nb % x == 0)
			return (0);
		else
			x += 2;
	}
	return (nb);
}

int		ft_find_next_prime(int nb)
{
	int x;

	x = 3;
	if (nb <= 2)
		return (2);
	if (nb <= 3)
		return (3);
	if (nb == 2147483647)
		return (nb);
	if (is_prime(nb, x))
		return (nb);
	while (1)
	{
		if (is_prime(nb, x))
			break ;
		else
			nb++;
	}
	return (nb);
}
#include <stdio.h>
int main(void)
{
	int i = 1;
	printf("%d\n", ft_find_next_prime(2100999999));
	while (++i < 100)
		printf("%d\n", ft_find_next_prime(i));
	return (0);
}
