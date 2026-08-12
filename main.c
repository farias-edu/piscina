/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:38:27 by btrainor          #+#    #+#             */
/*   Updated: 2026/08/12 14:41:42 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int main(void)
{
    t_map   map;

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
    return (0);
}
