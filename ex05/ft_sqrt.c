/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:45:00 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:08:42 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	else
		return (0);
}

/*
#include <stdio.h>

void f(int n) {
	int r = ft_sqrt(n);
	printf("%d -> %d\n", n, r);
}

int main() {
	f(-1);
	f(0);
	f(1);
	f(2);
	f(-2);
	f(3);
	f(4);
	f(1024);
	f(81);
}
//*/
