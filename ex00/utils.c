/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:44:39 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 19:55:45 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

/* ft_strlen Devuelve la longitud de una cadena */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* ft_putstr Escribe una cadena en la salida estandar "1" */
void	ft_putstr(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/* ft_sstrcmp Compara dos cadenas */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/* ft_isspace Detecta caracteres de espacio 
*  retorna 1 si detecta espacio.
*  retorna 0 si es cualquier otro valor.
*/
int	ft_isspace(int c)
{
	int	val;

	val = 0;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		val = 1;
	return (val);
}

/* ft_strdup Duplica una ccadena en memoria dinamica */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
