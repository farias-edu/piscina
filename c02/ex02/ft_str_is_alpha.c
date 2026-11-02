/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 10:39:57 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/02 15:52:32 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	c;
	int	is_letter;

	i = 0;
	while (str[i])
	{
		c = str[i];
		is_letter = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
		if (!is_letter)
			return (0);
		i++;
	}
	return (1);
}

/*
int main()
{
	char *tests[] = {"letters", "12497", "", "with.point", ".", "space "};
	int expected_results[] = {1, 0, 1, 0, 0, 0};
	int num_of_tests = 6;
	
	for (int i = 0; i < num_of_tests; i++) {
		int result = ft_str_is_alpha(tests[i]);
		printf("result: %d, expected: %d\n", result, expected_results[i]);
	}
}
//*/
