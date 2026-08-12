/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrainor <btrainor@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:39:18 by btrainor          #+#    #+#             */
/*   Updated: 2026/08/12 14:56:41 by btrainor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_map
{
    int     **array;
    int     rows;
    int     cols;
    char    empty;
    char    obstacle;
    char    full;
}   t_map;

int ft_getline(char **line, int *size, int fd);
int  read_header(t_map *map, char **line, size_t *capacity);
void read_row(t_map *map, char **line, size_t *capacity, int row);
t_map   read_map(void);
void    free_map(t_map *map);
void print_map(t_map *map, int debug);
int     min_local(int a, int b);
int     calc_solve(int **arr, int row, int column);
void    solve_map(t_map *map, int debug);
