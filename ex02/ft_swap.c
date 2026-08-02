/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:17:24 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 15:05:09 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int main() {
	int i = 24;
	int j = 10;
	printf("i: %d, j: %d\n", i, j);
	ft_swap(&i, &j);
	printf("i: %d, j: %d\n", i, j);
}
//*/
