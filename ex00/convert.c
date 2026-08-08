/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:34:42 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:50:49 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

/* ft_print_first_group: Imprime el primer grupo (tamanio variable). */
static int	ft_print_first_group(t_dict *dict, const char *num,
		int len, int *scale)
{
	int		first_len;
	char	group[4];
	int		i;

	first_len = len % 3;
	if (first_len == 0)
		first_len = 3;
	group[0] = '0';
	group[1] = '0';
	group[2] = '0';
	group[3] = '\0';
	i = 0;
	while (i < first_len)
	{
		group[3 - first_len + i] = num[i];
		i++;
	}
	if (!ft_print_group(dict, group, *scale))
		return (0);
	(*scale)--;
	return (1);
}

/* ft_print_rest_groups: Imprime los grupos restantes, 
*  siempre con un espacio antes.
*/
static int	ft_print_rest_groups(t_dict *dict, const char *num,
		int start, int scale)
{
	char	group[4];
	int		i;

	i = start;
	while (num[i])
	{
		ft_putstr(" ");
		group[0] = num[i];
		group[1] = num[i + 1];
		group[2] = num[i + 2];
		group[3] = '\0';
		if (!ft_print_group(dict, group, scale))
			return (0);
		i += 3;
		scale--;
	}
	return (1);
}

/* ft_convert_number: Funcion principal de conversion */
int	ft_convert_number(t_dict *dict, const char *num_str)
{
	int	len;
	int	scale;
	int	start;

	len = ft_strlen(num_str);
	if (len == 1 && num_str[0] == '0')
	{
		ft_putstr(ft_find_value(dict, "0"));
		return (1);
	}
	scale = (len - 1) / 3;
	if (!ft_print_first_group(dict, num_str, len, &scale))
		return (0);
	start = len % 3;
	if (start == 0)
		start = 3;
	if (num_str[start])
		return (ft_print_rest_groups(dict, num_str, start, scale));
	return (1);
}
