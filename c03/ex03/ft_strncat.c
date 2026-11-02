/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:51:23 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/03 12:17:27 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				tam_dest;
	unsigned int	i;

	tam_dest = 0;
	while (dest[tam_dest])
		tam_dest++;
	i = 0;
	while (src[i] && i < nb)
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
		int difference = 20;
		
		// mine implementation:
		for (j = 0; test1[j]; j++)
			src[j] = test1[i][j];
		src[j] = '\0';
		for (j = 0; test2[j]; j++)
			dest[j] = test2[i][j];
 	        dest[j] = '\0';
		ft_strncat(src, dest, strlen(dest)-difference);
		printf("mine: '%s', '%s'\n", src, dest);
		

		// correccion:
		for (j = 0; test1[j]; j++)
                        src[j] = test1[i][j];
                src[j] = '\0';
                for (j = 0; test2[j]; j++)
                        dest[j] = test2[i][j];
                dest[j] = '\0';
		strncat(src, dest, strlen(dest)-difference);
		printf("corr: '%s', '%s'\n\n", src, dest);
	}
}
//*/
