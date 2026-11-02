/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:36:11 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/03 19:51:04 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
int main() {
	char *test[] = {"", "a", "12", "alskd;jflkdkj", "\0"};
	for (int i = 0; i < 5; i++)
		printf("%s = %d\n", test[i], ft_strlen(test[i]));
}
*/
