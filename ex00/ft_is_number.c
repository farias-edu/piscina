/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:15:32 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 20:15:57 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_is_number Valida que la cadena contenga solo digitos */
static int	ft_is_number(const char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
