/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:34:13 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 11:39:51 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	c;
	int	is_uppercase;

	i = 0;
	while (str[i])
	{
		c = str[i];
		is_uppercase = (c >= 'A' && c <= 'Z');
		if (!is_uppercase)
			return (0);
		i++;
	}
	return (1);
}

/*
int main()
{
	char *tests[] = {"letters", "12497", "", ".", "space ", "UPPERCASE"};
	int expected_results[] = {0, 0, 1, 0, 0, 1};
	int num_of_tests = 6;
	
	for (int i = 0; i < num_of_tests; i++) {
		int result = ft_str_is_uppercase(tests[i]);
		printf("%d, result: %d, expect: %d\n", i+1, result, expected_results[i]);
	}
}
//*/
