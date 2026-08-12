/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:58:54 by btrainor          #+#    #+#             */
/*   Updated: 2026/08/12 15:03:59 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
                ft_putchar('0' + map->array[row][column]);
            else {
                if (map->array[row][column] == 1)
                    ft_putchar(map->empty);
                else if (map->array[row][column] == 0)
                    ft_putchar(map->obstacle);
                else
                    ft_putchar(map->full);
            }
            column++;
        }
        row++;
        ft_putchar('\n');
    }
    ft_putchar('\n');
}
