/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:25:43 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:54:20 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* ft_new_node Creates a new node (helper) */
t_dict	*ft_new_node(char *key, char *value)
{
	t_dict	*node;

	node = malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	return (node);
}

/* ft_add_entry Adds a node to the end of the list
 * (used in dict_parse.c)
 */
int	ft_add_entry(t_dict **dict, char *key, char *value)
{
	t_dict	*new;
	t_dict	*tmp;

	new = ft_new_node(key, value);
	if (!new)
		return (0);
	if (!*dict)
		*dict = new;
	else
	{
		tmp = *dict;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

 /* ft_find_value Searches for a key and returns its value (NULL if not found) */
char	*ft_find_value(t_dict *dict, const char *key)
{
	while (dict)
	{
		if (ft_strcmp(dict->key, key) == 0)
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

/* ft_free_dict Frees the entire list (using free) */
void	ft_free_dict(t_dict *dict)
{
	t_dict	*next;

	while (dict)
	{
		next = dict->next;
		free(dict->key);
		free(dict->value);
		free(dict);
		dict = next;
	}
}

/* ft_read_dict Reads the file into a buffer and calls the processor */
t_dict	*ft_read_dict(const char *filename)
{
	int		fd;
	char	buf[65536];
	ssize_t	bytes;
	t_dict	*dict;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes = read(fd, buf, sizeof(buf) - 1);
	close(fd);
	if (bytes <= 0)
		return (NULL);
	buf[bytes] = '\0';
	dict = NULL;
	if (!ft_process_buffer(buf, &dict))
	{
		ft_free_dict(dict);
		return (NULL);
	}
	return (dict);
}
