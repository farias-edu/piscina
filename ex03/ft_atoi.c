/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2026/08/03 19:00:00 by edfarias	       #+#    #+#	      */
/*   Updated: 2026/08/04 16:59:03 by edfarias         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>
//#include <stdlib.h>

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
	int		i;
	int		start_dig;
	int		final_dig;

	neg = 0;
	i = 0;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	if (!str[i])
		return (0);
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
	char blanks[] = {'\f', '\n', '\r', '\t', '\v', '-', '\0'};
	printf("%d\n", ft_atoi(blanks));	
	printf("%d\n\n", ft_atoi(" 09---+--+1234ab567")); // 09
	printf("%d\n\n", ft_atoi(" ---+--+12 34ab567")); // -12
	printf("%d\n\n", ft_atoi(" ---+--+12-34ab567")); // -12
	printf("%d\n\n", ft_atoi(" ---+---+1234ab567")); // 1234
	//" ---+--+12 34ab567" -> -12
	//" ---+--+12-34ab567" -> -12 
	//" ---+--+1234a b567" -> -1234
	//" ---+--+1234a+b567" -> -1234
	//" ---+--+1234a-b567" -> -1234
	printf("%d\n\n", ft_atoi("2147483647"));
	printf("%d\n\n", ft_atoi("-2147483648"));


	printf("standard: %d\n", atoi(" ---+--+1234ab567"));
	
	printf("%d\n\n", ft_atoi("-1"));
	printf("%d\n\n", ft_atoi("1"));
	printf("%d\n\n", ft_atoi("0"));
	printf("%d\n\n", ft_atoi("-0"));
	printf("%d\n\n", ft_atoi(""));
	printf("tab: %d\n", ft_atoi("	"));
	printf("%d\n\n", ft_atoi(" -+-2147483647"));

}
//*/
