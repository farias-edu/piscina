/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:56:03 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:02:55 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>

int f(int nb) {
	return ft_recursive_factorial(nb);
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
