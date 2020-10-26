/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:16:35 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/20 19:16:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int is_upper;

	i = 0;
	is_upper = 1;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
				(str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (is_upper && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!is_upper && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			is_upper = 0;
		}
		else
			is_upper = 1;
		i++;
	}
	return (str);
}
