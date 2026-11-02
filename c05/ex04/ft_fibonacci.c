/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:22:23 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/08 13:06:53 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
#include <stdio.h>

int f(int nb) {
	return ft_fibonacci(nb);
}

int main() {
	printf("%d: %d\n", 0, f(0));
	printf("%d: %d\n", 1, f(1));
	printf("%d: %d\n", -1, f(-1));
	printf("%d: %d\n", 2, f(2));
	printf("%d: %d\n", 3, f(3));
	printf("%d: %d\n", 4, f(4));
	printf("%d: %d\n", 5, f(5));
	printf("%d: %d\n", 45, f(45));
}
//*/
