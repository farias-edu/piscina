/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:38:10 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 15:06:59 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	t;

	t = 0;
	while (str[t])
		t++;
	return (t);
}

/*
int	main(void)
{
	printf("%d\n", ft_strlen("teste"));
}
*/
