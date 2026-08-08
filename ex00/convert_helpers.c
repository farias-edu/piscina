/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:42:30 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:51:56 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

/* ft_print_key: Busca e imprime el valor de una clave */
int	ft_print_key(t_dict *dict, char *key)
{
	char	*val;

	val = ft_find_value(dict, key);
	if (!val)
		return (0);
	ft_putstr(val);
	return (1);
}

/* ft_print_teens: Imprime 10‑19 (clave de dos digitos) */
static int	ft_print_teens(t_dict *dict, const char *str)
{
	char	key[3];

	key[0] = str[0];
	key[1] = str[1];
	key[2] = '\0';
	return (ft_print_key(dict, key));
}

/* ft_print_tens: Imprime 20‑99 (decena + espacio + unidad) */
static int	ft_print_tens(t_dict *dict, const char *str)
{
	char	key[3];
	int		ret;

	key[0] = str[0];
	key[1] = '0';
	key[2] = '\0';
	ret = ft_print_key(dict, key);
	if (!ret)
		return (0);
	if (str[1] != '0')
	{
		ft_putstr(" ");
		key[0] = str[1];
		key[1] = '\0';
		return (ft_print_key(dict, key));
	}
	return (1);
}

/* ft_print_two_digits: Imprime un numero de dos digitos (10‑99) */
int	ft_print_two_digits(t_dict *dict, const char *str)
{
	int		n;
	char	key[2];

	if (str[0] == '0')
	{
		key[0] = str[1];
		key[1] = '\0';
		return (ft_print_key(dict, key));
	}
	n = (str[0] - '0') * 10 + (str[1] - '0');
	if (n < 20)
		return (ft_print_teens(dict, str));
	return (ft_print_tens(dict, str));
}
