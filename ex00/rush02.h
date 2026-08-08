/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:42:24 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 16:23:40 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* utils.c file */
size_t	ft_trlen(const char *str);
void	ft_putstr(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(int c);
char	*ft_strdup(const char *s);
