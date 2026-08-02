/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2026/08/02 11:13:05 by edfarias	       #+#    #+#	      */
/*   Updated: 2026/08/02 16:15:19 by edfarias         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	c;
	int	is_lowercase;

	i = 0;
	while (str[i])
	{
		c = str[i];
		is_lowercase = (c >= 'a' && c <= 'z');
		if (!is_lowercase)
			return (0);
		i++;
	}
	return (1);
}

/*
int main()
{
	char *tests[] = {"letters", "12497", "", ".", "space ", "UPPERCASE"};
	int expected_results[] = {1, 0, 1, 0, 0, 0};
	int num_of_tests = 6;
	
	for (int i = 0; i < num_of_tests; i++) {
		int result = ft_str_is_lowercase(tests[i]);
		printf("%d, result: %d, expect: %d\n", i+1, result, expected_results[i]);
	}
}
//*/
