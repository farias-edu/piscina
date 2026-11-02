/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:16:36 by btrainor          #+#    #+#             */
/*   Updated: 2026/08/12 15:17:01 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int  read_header(t_map *map, char **line, size_t *capacity)
{
    int length;

    if (getline(line, capacity, stdin) == -1) return (0);
    length = strlen(*line);
    map->rows = atoi(*line);
    map->empty = (*line)[length - 4];
    map->obstacle = (*line)[length - 3];
    map->full = (*line)[length - 2];
    return (1);
}

void read_row(t_map *map, char **line, size_t *capacity, int row)
{
    int column;

    getline(line, capacity, stdin);
    if (row == 0)
        map->cols = strlen(*line) - 1;
    map->array[row] = malloc(sizeof(int) * map->cols);
    column = 0;
    while (column < map->cols)
    {
        map->array[row][column] = 1;
        if ((*line)[column] == map->obstacle)
            map->array[row][column] = 0;
        column++;
    }
}

t_map   read_map(void)
{
    t_map   map;
    char    *line;
    size_t  capacity;
    int     row;

    map = (t_map){NULL, 0, 0, 0, 0, 0};
    line = NULL;
    capacity = 0;
    if (!read_header(&map, &line, &capacity))
        return (map);
    map.array = malloc(sizeof(int *) * map.rows);
    row = 0;
    while (row < map.rows)
        read_row(&map, &line, &capacity, row++);
    free(line);
    return (map);
}
