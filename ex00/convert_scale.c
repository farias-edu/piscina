/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:56:21 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 18:58:55 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* ft_print_exact Busca la clave exacta (string) y la imprime si existe */
int	ft_print_exact(t_dict *dict, const char *str, int len)
{
	char	key[4];
	int		i;

	if (len > 3)
		return (0);
	i = 0;
	while (i < len)
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (ft_print_key(dict, key));
}

/* ft_build_scale_key Construye la clave de la escala (ej: "1000" para mil) */
char	*ft_build_scale_key(t_dict *dict, int scale)
{
	char	key[64];
	int		i;

	if (scale <= 0)
		return (NULL);
	key[0] = '1';
	i = 1;
	while (i <= scale * 3)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (ft_find_value(dict, key));
}

/* ft_is_zero_group Verifica si un grupo de 3 dígitos es todo ceros */
int	ft_is_zero_group(const char *str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

/* ft_print_group_exact Intenta imprimir la clave exacta 
*  del grupo con su escala
*/
int	ft_print_group_exact(t_dict *dict, const char *str, int scale)
{
	char	*scale_val;

	if (!ft_print_exact(dict, str, 3))
		return (0);
	if (scale > 0)
	{
		scale_val = ft_build_scale_key(dict, scale);
		if (!scale_val)
			return (0);
		ft_putstr(" ");
		ft_putstr(scale_val);
	}
	return (1);
}
