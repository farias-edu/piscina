/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2026/08/03 19:00:00 by edfarias	       #+#    #+#	      */
/*   Updated: 2026/08/03 19:52:18 by edfarias         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	calc_total(char *str, int start_dig, int final_dig)
{
	int	pot10;
	int	i;
	int	total;

	pot10 = 1;
	i = final_dig - 1;
	total = 0;
	while (i >= start_dig)
	{
		total += (str[i] - '0') * pot10;
		pot10 *= 10;
		i--;
	}
	return (total);
}

int	ft_atoi(char *str)
{
	int		neg;
	char	*p;
	int		start_dig;
	int		final_dig;

	neg = 0;
	p = str;
	while (*p)
	{
		if (*p == '-')
			neg++;
		p++;
	}
	start_dig = 0;
	while ((str[start_dig]) < '0' || (str[start_dig]) > '9')
		start_dig++;
	final_dig = start_dig;
	while ((str[final_dig]) >= '0' && (str[final_dig] <= '9'))
		final_dig++;
	if (neg % 2)
		return (-calc_total(str, start_dig, final_dig));
	else
		return (calc_total(str, start_dig, final_dig));
}

/*
int	main(void)
{
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("-0"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi(" -+-2147483647"));
}
//*/
