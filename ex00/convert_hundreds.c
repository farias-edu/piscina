/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hundreds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:13:08 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:52:57 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* ft_print_hundreds_parts Imprime las centenas sin verificar clave
*  exacta. (Se puede asumir que str[0] != '0')
*/
int	ft_print_hundreds_parts(t_dict *dict, const char *str)
{
	char	key_unit[2];
	char	*val_unit;
	char	*val_hundred;

	key_unit[0] = str[0];
	key_unit[1] = '\0';
	val_unit = ft_find_value(dict, key_unit);
	if (!val_unit)
		return (0);
	val_hundred = ft_find_value(dict, "100");
	if (!val_hundred)
		return (0);
	ft_putstr(val_unit);
	ft_putstr(" ");
	ft_putstr(val_hundred);
	if (!(str[1] == '0' && str[2] == '0'))
	{
		ft_putstr(" ");
		return (ft_print_0_99(dict, str + 1, 2));
	}
	return (1);
}

/* ft_print_0_99 Imprime 0‑99: primero busca clave exacta, 
*  si no, usa la descomposicion 
*/
int	ft_print_0_99(t_dict *dict, const char *str, int len)
{
	if (ft_print_exact(dict, str, len))
		return (1);
	return (ft_print_two_digits(dict, str));
}

/* ft_print_hundreds: Imprime centenas: primero busca clave exacta, 
*  si no, descompone.
*/
int	ft_print_hundreds(t_dict *dict, const char *str)
{
	if (ft_print_exact(dict, str, 3))
		return (1);
	if (str[0] == '0')
		return (ft_print_0_99(dict, str + 1, 2));
	return (ft_print_hundreds_parts(dict, str));
}

/* ft_should_use_exact: Retorna 0 si el grupo es "100" y la clave "100"
 * tiene el valor "hundred" (para forzar descomposición y obtener "one hundred").
 * En caso contrario, retorna 1.
 */
int	ft_should_use_exact(t_dict *dict, const char *str)
{
	char	*h_val;

	if (str[0] == '1' && str[1] == '0' && str[2] == '0')
	{
		h_val = ft_find_value(dict, "100");
		if (h_val)
		{
			h_val = ft_find_value(dict, "1");
			ft_putstr(h_val);
			ft_putstr(" ");
			return (0);
		}
	}
	return (1);
}

/* ft_print_group Imprime un grupo de 3 digitos con su escala */
int	ft_print_group(t_dict *dict, const char *str, int scale)
{
	char	*scale_val;

	if (ft_is_zero_group(str))
		return (1);
	if (ft_should_use_exact(dict, str)
		&& ft_print_group_exact(dict, str, scale))
		return (1);
	scale_val = ft_build_scale_key(dict, scale);
	if (scale > 0 && !scale_val)
		return (0);
	if (!ft_print_hundreds(dict, str))
		return (0);
	if (scale > 0)
	{
		ft_putstr(" ");
		ft_putstr(scale_val);
	}
	return (1);
}
