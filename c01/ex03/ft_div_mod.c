/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:18:42 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 15:05:42 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = (int) a / b;
	*mod = (a % b);
}

/*
int main() {
	int i = 13;
	int j = 5;
	int d, m;
	ft_div_mod(i, j, &d, &m);
	printf("d: %d, m: %d\n", d, m);
}
//*/
