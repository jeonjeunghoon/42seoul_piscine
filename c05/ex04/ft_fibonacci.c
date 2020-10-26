/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:28:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/15 23:17:49 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rec(int a, int b, int i, int index)
{
	if (i == index)
		return (b);
	i++;
	return (rec(b, a + b, i, index));
}

int		ft_fibonacci(int index)
{
	int a;
	int b;
	int i;

	a = 0;
	b = 1;
	i = 1;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	return (rec(a, b, i, index));
}
