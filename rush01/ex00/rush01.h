/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:07:33 by yeonkim           #+#    #+#             */
/*   Updated: 2020/07/12 22:12:31 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

int		start_check(int **arr, int *argv);
void	solve(void);
int		check_error(int argc, char **argv);
int		**malloc_map(int size);
void	free_map(int **map, int size);
void	dfs(int r, int c, int n);

#endif
