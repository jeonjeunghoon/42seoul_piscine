/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:17:18 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/15 19:56:01 by jeunjeon         ###   ########.fr       */
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
	if (argc == 1)
	{
		print(argv[0]);
		write(1, "\n", 1);
	}
	return (0);
}
