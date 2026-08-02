/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:19:25 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 15:06:03 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aa;
	int	bb;

	aa = *a;
	bb = *b;
	*a = (int) aa / bb;
	*b = (aa % bb);
}

/*
int main() {
	int i = 13;
	int j = 5;
	ft_ultimate_div_mod(&i, &j);
	printf("a: %d, b: %d\n", i, j);
}
//*/
