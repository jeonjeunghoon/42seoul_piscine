/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 23:02:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/07/12 23:03:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		c_u(int **arr, int *argv, int h, int n)
{
	int i;
	int j;
	int k;

	j = 0;
	k = -1;
	while (++j <= 4)
	{
		h = 0;
		n = 0;
		i = 0;
		while (++i <= 4)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
		}
		if (argv[++k] != n)
			return (0);
	}
	return (1);
}

int		c_d(int **arr, int *argv, int h, int n)
{
	int i;
	int j;
	int k;

	j = 5;
	k = 8;
	while (--j <= 1)
	{
		h = 0;
		n = 0;
		i = 5;
		while (--i <= 1)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
		}
		if (argv[--k] != n)
			return (0);
	}
	return (1);
}

int		r_l(int **arr, int *argv, int h, int n)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 7;
	while (++i <= 4)
	{
		h = 0;
		n = 0;
		j = 0;
		while (++j <= 4)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
		}
		if (argv[++k] != n)
			return (0);
	}
	return (1);
}

int		r_r(int **arr, int *argv, int h, int n)
{
	int i;
	int j;
	int k;

	i = 5;
	k = 16;
	while (--i >= 1)
	{
		h = 0;
		n = 0;
		j = 5;
		while (--j >= 1)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
		}
		if (argv[--k] != n)
			return (0);
	}
	return (1);
}

int		start_check(int **arr, int *argv)
{
	int h;
	int n;

	h = 0;
	n = 0;
	if (!(c_u(arr, argv, h, n)))
		return (0);
	if (!(c_d(arr, argv, h, n)))
		return (0);
	if (!(r_l(arr, argv, h, n)))
		return (0);
	if (!(r_r(arr, argv, h, n)))
		return (0);
	return (1);
}
