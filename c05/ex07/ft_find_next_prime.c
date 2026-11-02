/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:32:13 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:11:07 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 0)
		nb = -nb;
	if (nb < 2)
		return (0);
	i = 2;
	while (nb % i)
		i++;
	return (nb == i);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/*
#include <stdio.h>

void f(int n) {
	int r = ft_find_next_prime(n);
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
