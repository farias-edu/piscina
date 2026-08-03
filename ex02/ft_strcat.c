/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:51:49 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/03 12:16:58 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char	*ft_strcat(char *dest, char *src)
{
	int	tam_dest;
	int	i;

	tam_dest = 0;
	while (dest[tam_dest])
		tam_dest++;
	i = 0;
	while (src[i])
	{
		dest[tam_dest + i] = src[i];
		i++;
	}
	dest[tam_dest + i] = '\0';
	return (dest);
}

/*
int main() {
	char *test1[] = {"", "", "a", "a", "test", "testing"};
	char *test2[] = {"", "a", "", "a", "testing", "test"};
	int t = 6;
	
	for (int i = 0; i < t; i++) {
	        char *src  = (char *) malloc(strlen(test1[i]) + strlen(test2[i]));
	        char *dest = (char *) malloc(strlen(test1[i]) + strlen(test2[i]));
		
		int j;
		for (j = 0; test1[j]; j++)
			src[j] = test1[i][j];
		src[j] = '\0';

		for (j = 0; test2[j]; j++)
			dest[j] = test2[i][j];
 	        dest[j] = '\0';
		
		printf("antes: '%s', '%s'\n", src, dest);
		ft_strcat(src, dest);
		printf("depois: '%s', '%s'\n\n", src, dest);
	}
}
//*/
