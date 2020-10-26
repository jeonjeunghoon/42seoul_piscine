/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:11:01 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 21:27:03 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_io.h"

void	ft_putchar_to(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putchar(char c)
{
	ft_putchar_to(OUT, c);
}
