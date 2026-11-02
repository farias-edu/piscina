/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 12:07:46 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/10 12:33:55 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*a;
	int	t;
	int	i;

	t = max - min;
	if (t <= 0)
	{
		*range = NULL;
		return (0);
	}
	a = (int *) malloc(sizeof(int) * t);
	if (!a)
		return (-1);
	else
		*range = a;
	i = 0;
	while (i < t)
	{
		a[i] = min;
		min++;
		i++;
	}
	return (t);
}

/*
#include <stdio.h>

void f(int a, int b) {
	int max_test = 10;
	int t = b - a;
	printf("(%d, %d) -> ", a, b);
	int *arr = (int*) malloc(sizeof(int) * max_test);
	int result = ft_ultimate_range(&arr, a, b);
	printf("%d: ", result);
	if (t > 0) {
	
		for (int i = 0; i < t; i++)
			printf("%d, ", arr[i]);
	}
	else if (arr == NULL) {
		printf("NULL");
	}
	printf("\n");
}

int main() {
	f(0,0);
	f(-5,-1);
	f(-1, -5);
	f(-1, 0);
	f(-1, 1);
	f(1, 10);
}
//*/
