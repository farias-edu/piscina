/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:38:27 by btrainor          #+#    #+#             */
/*   Updated: 2026/08/12 17:22:06 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int main(int argc, char **argv)
{
    t_map   map;
	int		i;
	int		fd;

	if (argc == 1)
	{
			fd = 0;
			map = read_map();
			if (map.array == NULL)
				return (1);
			int debug = 1;
			if (debug) {
				printf("mapa inicial:\n");
				print_map(&map, 0);
				printf("conversion para 0 e 1:\n");
				print_map(&map, 1);
			}
			solve_map(&map, debug);
			if (debug) {
				printf("solucion final:\n");
				print_map(&map, 0);
			}

			free_map(&map);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			printf("%s\n", argv[i]);
			fd = open(argv[i], O_RDONLY);
			//map = read_map(fd);
			close(fd);
		}
	}
    return (0);
}
