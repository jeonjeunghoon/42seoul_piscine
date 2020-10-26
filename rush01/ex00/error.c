/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongbkim <dongbkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 23:06:36 by dongbkim          #+#    #+#             */
/*   Updated: 2020/07/12 23:06:43 by dongbkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	*g_input;

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	over_sum(int *arr, int l)
{
	if ((arr[l - 4] + arr[l] > 5) || (arr[l - 4] + arr[l] < 3))
		return (print_error());
	return (1);
}

int	is_digit(char **argv, int i, int length)
{
	g_input[length] = argv[1][i] - '0';
	if ((length > 3 && length < 8) || (length > 11 && length < 16))
	{
		if (!over_sum(g_input, length))
			return (0);
	}
	else if (length > 16)
		return (print_error());
	length++;
	return (1);
}

int	check_error(int argc, char **argv)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (argc < 2)
		return (print_error());
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] > '0' && argv[1][i] < '5')
		{
			if (!is_digit(argv, i, length))
				return (0);
			length++;
		}
		else if (argv[1][i++] == ' ')
			continue;
		else
			return (print_error());
		i++;
	}
	if (length != 16)
		return (print_error());
	return (1);
}
