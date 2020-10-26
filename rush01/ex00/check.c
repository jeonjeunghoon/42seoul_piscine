#include <stdio.h>

int		c_u(char **arr, char *argv, int h, int n)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = -1;
	while (++j < 4)
	{
		while (++i < 4)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
			if (argv[++k] != n)
				return (0);
		}
	}
	return (1);
}

int		c_d(char **arr, char *argv, int h, int n)
{
	int i;
	int j;
	int k;

	i = 4;
	j = 4;
	k = 3;
	while (--j <= 0)
	{
		while (--i <= 0)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
			if (argv[++k] != n)
				return (0);
		}
	}
	return (1);
}

int		r_l(char **arr, char *argv, int h, int n)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = 7;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
			if (argv[++k] != n)
				return (0);
		}
	}
	return (1);
}

int		r_r(char **arr, char *argv, int h, int n)
{
	int i;
	int j;
	int k;

	i = 4;
	j = 4;
	k = 11;
	while (--i >= 0)
	{
		while (--j >= 0)
		{
			if (arr[i][j] > h)
			{
				h = arr[i][j];
				n++;
			}
			if (argv[++k] != n)
				return (0);
		}
	}
	return (1);
}

int		start_check(char **arr, char *argv)
{
	int h;
	int n;

	h = 0;
	n = 0;
	if (!(c_u(arr, argv, h, n)))
		return (0);
	else if (!(c_d(arr, argv, h, n)))
		return (0);
	else if (!(r_l(arr, argv, h, n)))
		return (0);
	else if (!(r_r(arr, argv, h, n)))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char arr[4][4];
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			arr[i][j] = '1';
		}
	}
	start_check(arr, argv[1]);
	return (0);
}
