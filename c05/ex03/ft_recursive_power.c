/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:16:58 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:05:45 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*

#include <stdio.h>

int f(int a, int b) {
	printf("%d^%d = ", a, b);
	return ft_recursive_power(a, b);
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
