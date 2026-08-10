/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:35:48 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/10 11:45:45 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	t;
	int	i;

	t = max - min;
	if (t <= 0)
		return (NULL);
	a = (int *) malloc(sizeof(int) * t);
	i = 0;
	while (i < t)
	{
		a[i] = min;
		min++;
		i++;
	}
	return (a);
}

/*
#include <stdio.h>

void f(int a, int b) {
	int *aa = ft_range(a, b);
	int t = b - a;
	printf("(%d, %d)->", a, b);
	if (t > 0)
		for (int i = 0; i < t; i++)
			printf("%d, ", aa[i]);
	printf("\n");
}

int main() {
	f(0,0);
	f(-5,-1);
	f(-1, -5);
	f(-1, 1);
	f(-2, 2);
}
//*/
