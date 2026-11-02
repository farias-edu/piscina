/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:14:22 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/03 12:17:53 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

/*
int main() {
	char *test1[] = {"", "", "a", "a", "test", "testing"};
	char *test2[] = {"", "a", "", "a", "testing", "test"};
	int t = 6;
	
	for (int i = 0; i < t; i++) {
		int mine = ft_strcmp(test1[i], test2[i]);
		int correct = strcmp(test1[i], test2[i]);
		printf("s1:%s, s2:%s, mine: %d, correct: %d\n", 
			test1[i], test2[i], mine, correct);
	}
}
//*/
