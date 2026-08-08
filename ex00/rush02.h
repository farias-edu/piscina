/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:42:24 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 18:59:59 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
size_t		ft_trlen(const char *str);
void		ft_putstr(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(int c);
char		*ft_strdup(const char *s);

/* dict.c */
t_dict		*ft_new_node(char *key, char *value);
int			ft_add_entry(t_dict **dict, char *key, char *value);
char		*ft_find_value(t_dict *dict, const char *key);
void		ft_free_dict(t_dict *dict);
t_dict		*ft_read_dict(const char *filename);

/* dict_parse.c */
static void	ft_trim(char *str);
static int	ft_parse_line(char *line, char **key, char **value);
static int	ft_process_line(char *line, t_dict **dict);
int			ft_process_buffer(char *buf, t_dict **dict);
