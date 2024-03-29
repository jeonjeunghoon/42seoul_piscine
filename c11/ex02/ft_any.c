/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:51:28 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 18:51:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char))
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) != 0)
		{
			res = 1;
			break ;
		}
		i++;
	}
	return (res);
}
