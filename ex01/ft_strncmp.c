/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:29:29 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/03 14:11:37 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < n))
		i++;
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}

/*
int main() {
	char *test1[] = {"", "", "a", "a", "test", "testing"};
	char *test2[] = {"", "a", "", "a", "testing", "test"};
	int t = 6;
	
	for (int i = 0; i < t; i++) {
		int mine = ft_strncmp(test1[i], test2[i], strlen(test1[i]));
		int correct = strncmp(test1[i], test2[i], strlen(test1[i]));
		printf("s1:%s, s2:%s, mine: %d, correct: %d\n", 
			test1[i], test2[i], mine, correct);
	}
}
//*/
