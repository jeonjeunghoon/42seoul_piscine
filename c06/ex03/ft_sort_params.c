/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:07:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/23 12:52:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print(char *c)
{
	while (*c)
		write(1, c++, 1);
}

void		swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

void		sort(char **str, int size, int current)
{
	int		i;
	int		is_swap;

	i = current;
	while (1)
	{
		i = current;
		is_swap = 0;
		while (i < size)
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				swap(&str[i], &str[i + 1]);
				is_swap = 1;
			}
			i++;
		}
		if (!is_swap)
			break ;
	}
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc > 2)
		sort(argv, argc - 1, 1);
	i = 0;
	while (++i < argc)
	{
		print(argv[i]);
		print("\n");
	}
}
