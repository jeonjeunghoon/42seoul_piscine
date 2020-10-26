/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywoo <dndydtmd@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:18:51 by ywoo              #+#    #+#             */
/*   Updated: 2020/07/22 11:09:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define INPUT_NUM_ERR_MSG "Error"
# define DEFAULT_FILE "dictionary/numbers.dict"
# define MAX_BUFF 1024
# define VALID_NUM_LEN 50
# define VALID_MIN_DICT 41

typedef struct		s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

extern	t_dict		*g_dict;
extern	int			g_dict_error;
extern	int			g_read_error;
extern	int			g_input_num_error;
extern	int			g_open_error;
extern	int			g_is_first;
extern	int			g_parse_error;
extern	int			g_eof;
extern	char		*g_num;
extern	char		*g_line;
extern	char		**g_tmp_key;

t_dict				*create_ele(char *key, char *val);
void				push_front(char *key, char *val);
void				build_dict(char *file);
void				insert_key_value(char *str);
char				*get_val(char *key);

char				*ft_split(char *str);

void				ft_strcpy(char *dest, char *begin, char *end);
int					ft_strlen(char *str);
int					ft_is_equal(char *s1, char *s2);

char				*read_line(int fd);
void				check_key(void);
void				dict_error(int i);
int					all_space(char *str);
char				*chk_argv_zero(char *str);
char				*make_sig(int idx_zero, char *str);

void				print(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				print_error_msg(char *str);

int					is_white_space(char c);
int					ft_is_number(char c);
int					ft_is_valid_number(char *str);
int					is_valid_key_value(char *str);
int					check_arg(int argc, char **argv);

void				rush(int argc, char *argv[]);
void				convert_num(char *num);
char				*build_unit_str(int cnt);

int					before_split_error(char *str);
char				*chk_error_key(char *str);

void				free_list(t_dict *head);
int					safe_mal_guard(char *str);
int					safe_dic_guard(t_dict *dic);

#endif
