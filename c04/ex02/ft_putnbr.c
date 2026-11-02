/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:47:15 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/04 16:54:30 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_num(int pot10, int nb)
{
	char	c;

	while (pot10 > 0)
	{
		c = ('0' + (nb / pot10));
		write(1, &c, 1);
		nb %= pot10;
		pot10 /= 10;
	}
}

void	ft_putnbr(int nb)
{
	long int	pot10;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	pot10 = 1;
	while (pot10 <= nb)
		pot10 *= 10;
	pot10 /= 10;
	if (!pot10)
		write(1, "0", 1);
	print_num(pot10, nb);
}

/*
int main() {
	ft_putnbr(2147483647);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-0);
	printf("\n");
	ft_putnbr(1);
	printf("\n");
	ft_putnbr(-1);
	printf("\n");
	ft_putnbr(2);
	printf("\n");
	ft_putnbr(-2);
}
//*/
