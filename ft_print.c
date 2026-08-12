/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:58:54 by btrainor          #+#    #+#             */
/*   Updated: 2026/08/12 15:00:35 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void print_map(t_map *map, int debug)
{
    int row;
    int column;

    row = 0;
    while (row < map->rows)
    {
        column = 0;
        while (column < map->cols)
        {
            if (debug)
                putchar('0' + map->array[row][column]);
            else {
                if (map->array[row][column] == 1)
                    putchar(map->empty);
                else if (map->array[row][column] == 0)
                    putchar(map->obstacle);
                else
                    putchar(map->full);
            }
            column++;
        }
        row++;
        putchar('\n');
    }
    putchar('\n');
}
