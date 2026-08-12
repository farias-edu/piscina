#include "ft_bsq.h"


void    free_map(t_map *map)
{
    int row;

    row = 0;
    while (row < map->rows)
        free(map->array[row++]);
    free(map->array);
}



int     calc_solve(int **arr, int row, int column)
{
    if (arr[row][column] == 0)
        return 0;
    if (row == 0 || column == 0)
        return 1;
    int min3 = min_local(arr[row-1][column], min_local(arr[row][column-1], arr[row-1][column-1]));
    return min3 + 1;
}

int		max_square(t_map *map, int *i, int *j)
{
	int 	max_value;
    int row;
    int column;

	max_value = 0;
    row = 0;
    while (row < map->rows)
    {
        column = 0;
        while (column < map->cols)
        {
            int temp = calc_solve(map->array, row, column);
            map->array[row][column] = temp;
            if (temp > max_value) {
                max_value = temp;
                *i = row;
                *j = column;
            }
            column++;
        }
        row++;
    }
	return (max_value);
}

void	normalize_map(t_map *map, int max_value, int i, int j)
{
    int row;
    int column;

    row = column = 0;
    while (row < map->rows)
    {
        column = 0;
        while (column < map->cols)
        {
            int in_square_line = (row > i-max_value && row <= i);
            int in_square_column = (column > j-max_value && column <= j);
            int is_in_square = in_square_line && in_square_column;
            if (is_in_square)
                map->array[row][column] = 8;
            else
                map->array[row][column] = (map->array[row][column] > 0);
            column++;
        }
        row++;
    }
}

void    solve_map(t_map *map, int debug)
{
    int max_value = 0;
    int i, j;

	max_value = max_square(map, &i, &j);
	normalize_map(map, max_value, i, j);
    if (debug) {
        printf("solucionado con calculos:\n");
        print_map(map, 1);
    }
    if (debug) {
        printf("normalizado para 0, 1 y 8:\n");
        print_map(map, 1);
    }
}
