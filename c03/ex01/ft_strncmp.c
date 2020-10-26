/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:06:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/11 15:33:50 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while ((s1[i] != '\0' || s2[j] != '\0') && (i < n && j < n))
	{
		if (s1[i] > s2[j])
			return (1);
		else if (s1[i] < s2[j])
			return (-1);
		i++;
		j++;
	}
	return (0);
}
