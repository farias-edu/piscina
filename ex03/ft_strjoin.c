/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfarias <edfarias@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:16:54 by edfarias          #+#    #+#             */
/*   Updated: 2026/08/10 14:04:16 by edfarias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	int	t;

	t = 0;
	while (str[t])
		t++;
	return (t);
}

int	ft_copy_pos(int pos, char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[pos + i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		tam_total;
	int		i;
	int		k;

	tam_total = 0;
	i = 0;
	while (i < size)
		tam_total += ft_strlen(strs[i++]);
	join = (char *) malloc((tam_total + 1) * sizeof(char));
	k = 0;
	i = 0;
	while (i < size - 1)
	{
		k += ft_copy_pos(k, join, strs[i]);
		k += ft_copy_pos(k, join, sep);
		i++;
	}
	if (i == size - 1)
		k += ft_copy_pos(k, join, strs[i]);
	join[k] = '\0';
	return (join);
}

/*
#include <stdio.h>

void f(int size, char **strs, char *sep) {
	printf("%d: {", size);
	for (int i = 0; i < size; i++) {
		printf("|%s|", strs[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("} ");
	printf(" con sep=|%s|\n", sep);

	char *result = ft_strjoin(size, strs, sep);
	printf("result: |%s|\n\n", result);
}

int main() {
	char *arr1[] = {"hola", "que", "tal", "?"};
	int size1 = 4;

	char *arr2[] = {"vacio", ""};
	int size2 = 2;

	char *arr3[] = {"", "", ""};
	int size3 = 3;

	char *arr4[] = {};
	int size4 = 0;

	char *arr5[] = {"uno"};
	int size5 = 1;

	char *sep1 = ".";
	char *sep2 = "teste";
	char *sep3 = "";

	char **casos[] = {arr1, arr2, arr3, arr4, arr5};
	char sizes[] = {size1, size2, size3, size4, size5};
	char *seps[] = {sep1, sep2, sep3};

	int n_arrays = 5;
	int n_seps = 3;
	for (int i = 0; i < n_arrays; i++)
		for (int j = 0; j < n_seps; j++)
			f(sizes[i], casos[i], seps[j]);
}
//*/
