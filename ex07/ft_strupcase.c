/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:16:53 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 14:48:44 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;
	int	c;
	int	is_lower;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		is_lower = (c >= 'a' && c <= 'z');
		if (is_lower)
		{
			str[i] = 'A' + (c - 'a');
		}
		i++;
	}
	return (str);
}

/*
int main()
{
	char test[] = {'a','.','C', ' ', '\0'};
	
	printf("%d, result: %s\n", 1, ft_strupcase(test));
}
//*/
