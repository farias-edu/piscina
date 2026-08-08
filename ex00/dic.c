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

#include <rush02.h>

/* ft_new_node Crea un nuevo nodo (auxiliar, estatica) */
static t_dict	*ft_new_node(char *key, char *value)
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

/* ft_add_entry Agrega un nodo al final de la lista 
*  (global, se usa en dict_parse.c) 
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

/* ft_find_value Busca una clave y devuelve su valor (NULL si no existe) */
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

/* ft_free_dict Libera toda la lista (con free) */
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

/* ft_read_dict Lee el archivo en un buffer y llama al procesador  */
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
