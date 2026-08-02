/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:41:08 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 16:28:00 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	c;
	int	is_not_printable;

	i = 0;
	while (str[i])
	{
		c = str[i];
		is_not_printable = (c >= 0 && c <= 31) || (c == 127);
		if (is_not_printable)
			return (0);
		i++;
	}
	return (1);
}

/*
int main()
{
	char *tests[] = {" ", "12497!", "", ".", "tab	", "UPPERCASE"};
	int expected_results[] = {1, 1, 1, 1, 0, 1};
	int num_of_tests = 6;
	
	for (int i = 0; i < num_of_tests; i++) {
		int result = ft_str_is_printable(tests[i]);
		printf("%d, result: %d, expect: %d\n", i+1, result, expected_results[i]);
	}
}
//*/
