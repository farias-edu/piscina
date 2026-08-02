/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:00:04 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 16:15:00 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	c;
	int	is_number;

	i = 0;
	while (str[i])
	{
		c = str[i];
		is_number = (c >= '0' && c <= '9');
		if (!is_number)
			return (0);
		i++;
	}
	return (1);
}

/*
int main()
{
	char *tests[] = {"letters", "12497", "", "with.point", ".", "space "};
	int expected_results[] = {0, 1, 1, 0, 0, 0};
	int num_of_tests = 6;
	
	for (int i = 0; i < num_of_tests; i++) {
		int result = ft_str_is_numeric(tests[i]);
		printf("%d, result: %d, expect: %d\n", i+1, result, expected_results[i]);
	}
}
//*/
