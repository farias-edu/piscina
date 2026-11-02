/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:00:33 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:04:36 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	total;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	total = nb;
	i = 1;
	while (i < power)
	{
		total *= nb;
		i++;
	}
	return (total);
}

/*

#include <stdio.h>

int f(int a, int b) {
	printf("%d^%d = ", a, b);
	return ft_iterative_power(a, b);
}

int main() {
	printf("%d\n", f(0, 0));
	printf("%d\n", f(0, 1));
	printf("%d\n", f(0, -1));
	printf("%d\n", f(1, 0));
	printf("%d\n", f(1, 1));
	printf("%d\n", f(1, 2));
	printf("%d\n", f(-1, -1));
	printf("%d\n", f(-1, 0));
	printf("%d\n", f(-1, 1));
	printf("%d\n", f(-1, 2));
	printf("%d\n", f(-1, 3));
	printf("%d\n", f(2, 10));
	printf("%d\n", f(-3, 4));
}
//*/
