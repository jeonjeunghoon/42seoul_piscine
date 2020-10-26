/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:00:36 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 19:08:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int flag;

	flag = 1;
	i = 0;
	while (i < length - 1 && flag)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			flag = 0;
		i++;
	}
	if (flag != 1)
	{
		flag = 1;
		i = 0;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
