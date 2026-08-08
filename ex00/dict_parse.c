/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:32:45 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:55:10 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

/* ft_trim Recorta espacios al inicio y final de una cadena */
static void	ft_trim(char *str)
{
	char	*end;

	while (*str && ft_isspace(*str))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end >= str && ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
}

/* ft_parse_line Parsea una linea: busca ':' y recorta espacios */
static int	ft_parse_line(char *line, char **key, char **value)
{
	char	*colon;

	colon = line;
	while (*colon && *colon != ':')
		colon++;
	if (*colon != ':')
		return (0);
	*colon = '\0';
	ft_trim(line);
	if (!*line)
		return (0);
	*key = line;
	colon++;
	while (*colon && ft_isspace(*colon))
		colon++;
	if (!*colon)
		return (0);
	*value = colon;
	ft_trim(*value);
	return (1);
}

/* ft_process_line Procesa una linea y la aniade al diccionario */
static int	ft_process_line(char *line, t_dict **dict)
{
	char	*key;
	char	*value;

	if (!ft_parse_line(line, &key, &value))
		return (0);
	return (ft_add_entry(dict, key, value));
}

/* ft_process_buffer Procesa el buffer completo linea por linea */
int	ft_process_buffer(char *buf, t_dict **dict)
{
	char	*line;
	char	*nl;

	line = buf;
	while (*line)
	{
		nl = line;
		while (*nl && *nl != '\n')
			nl++;
		if (*nl == '\n')
			*nl = '\0';
		if (*line != '\0')
		{
			if (!ft_process_line(line, dict))
				return (0);
		}
		line = nl + 1;
	}
	return (1);
}
