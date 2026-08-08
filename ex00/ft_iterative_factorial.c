/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:37:40 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:01:30 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	total;

	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	i = 2;
	total = 1;
	while (i <= nb)
	{
		total *= i;
		i++;
	}
	return (total);
}

/*
#include <stdio.h>

int f(int nb) {
	return ft_iterative_factorial(nb);
}

int main() {
	printf("%d: %d\n", 2, f(2));
	printf("%d: %d\n", 3, f(3));
	printf("%d: %d\n", 4, f(4));
	printf("%d: %d\n", 5, f(5));
	printf("%d: %d\n", 10, f(10));
	printf("%d: %d\n", 0, f(0));
	printf("%d: %d\n", 1, f(1));
	printf("%d: %d\n", -1, f(-1));
}
//*/
