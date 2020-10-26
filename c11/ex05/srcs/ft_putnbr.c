/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:13:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 21:26:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10);
		ft_putchar('0');
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
