/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:42:24 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:14:28 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef RUSH02_H
//# define RUSH02_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

/* utils.c file */
size_t			ft_strlen(const char *str);
void			ft_putstr(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(int c);
char			*ft_strdup(const char *s);

/* dict.c file */
static t_dict	*ft_new_node(char *key, char *value);
int				ft_add_entry(t_dict **dict, char *key, char *value);
char			*ft_find_value(t_dict *dict, const char *key);
void			ft_free_dict(t_dict *dict);
t_dict			*ft_read_dict(const char *filename);

/* dict_parse.c file */
static void		ft_trim(char *str);
static int		ft_parse_line(char *line, char **key, char **value);
static int		ft_process_line(char *line, t_dict **dict);
int				ft_process_buffer(char *buf, t_dict **dict);

/* convert_scale.c file */
int				ft_print_exact(t_dict *dict, const char *str, int len);
char			*ft_build_scale_key(t_dict *dict, int scale);
int				ft_is_zero_group(const char *str);
int				ft_print_group_exact(t_dict *dict, const char *str, int scale);

/* convert_hundreds.c file */
static int	ft_print_hundreds_parts(t_dict *dict, const char *str);
int	ft_print_0_99(t_dict *dict, const char *str, int len);
int	ft_print_hundreds(t_dict *dict, const char *str);
int	ft_print_group(t_dict *dict, const char *str, int scale);

/* convert_helpers.c */
int	ft_print_key(t_dict *dict, char *key);
static int	ft_print_teens(t_dict *dict, const char *str);
static int	ft_print_tens(t_dict *dict, const char *str);
int	ft_print_two_digits(t_dict *dict, const char *str);

/* convert.c file */
static int	ft_print_first_group(t_dict *dict, const char *num, int len, int *scale);
static int	ft_print_rest_groups(t_dict *dict, const char *num, int start, int scale);
int	ft_convert_number(t_dict *dict, const char *num_str);

//#endif
