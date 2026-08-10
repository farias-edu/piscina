/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 10:46:32 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/10 11:34:02 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *src)
{
	int	t;

	t = 0;
	while (src[t])
		t++;
	return (t);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		i;

	size = ft_strlen(src);
	dup = (char *) malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

void f(char *s) {
	char *dup = ft_strdup(s);
	printf("%s->%s\n", s, dup);
}

int main() {
	f("teste");
	f("");
	f("a");
}
//*/
