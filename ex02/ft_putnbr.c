/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:47:15 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/03 20:05:25 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	long int	pot10;
	char		c;

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
	while (pot10 > 0)
	{
		c = '0' + (nb / pot10);
		write(1, &c, 1);
		nb %= pot10;
		pot10 /= 10;
	}
}

/*
int main() {
	ft_putnbr(2147483646);
	ft_putnbr(-2147483645);
	ft_putnbr(0);
	ft_putnbr(-0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(2);
	ft_putnbr(-2);
}
//*/
