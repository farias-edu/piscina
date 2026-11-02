/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:50:59 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 14:54:07 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;
	int	c;
	int	is_upper;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		is_upper = (c >= 'A' && c <= 'Z');
		if (is_upper)
		{
			str[i] = 'a' + (c - 'A');
		}
		i++;
	}
	return (str);
}

/*
int main()
{
	char test[] = {'a','.','C', ' ', '\0'};
	
	printf("%d, result: %s\n", 1, ft_strlowcase(test));
}
//*/
