#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_map
{
    int     **array;
    int     rows;
    int     cols;
    char    empty;
    char    obstacle;
    char    full;
}   t_map;

int  read_header(t_map *map, char **line, size_t *capacity)
{
    int length;

    if (getline(line, capacity, stdin) == -1)
        return (0);
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

void    free_map(t_map *map)
{
    int row;

    row = 0;
    while (row < map->rows)
        free(map->array[row++]);
    free(map->array);
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

int     min_local(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
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

void    solve_map(t_map *map, int debug)
{
    int row;
    int column;
    int max_value = 0;
    int i, j;

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
                i = row;
                j = column;
            }
            column++;
        }
        row++;
    }

    if (debug) {
        printf("solucionado con calculos:\n");
        print_map(map, 1);
    }
    
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

    if (debug) {
        printf("normalizado para 0, 1 y 8:\n");
        print_map(map, 1);
    }

}

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
