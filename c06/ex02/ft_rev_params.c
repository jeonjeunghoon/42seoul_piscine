/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:54:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/14 23:54:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *c)
{
	while (*c != '\0')
	{
		write(1, &*c, 1);
		c++;
	}
}

int		main(int argc, char **argv)
{
	while (--argc > 0)
	{
		print(argv[argc]);
		write(1, "\n", 1);
	}
	return (0);
}
