#ifndef FDF_H
#define FDF_H

#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct
{
    int width;
    int height;
    int **z_matrix;

    void *mlx_ptr;
    void *win_ptr;
}   fdf;

void    read_file(char *file_name, fdf *data);

#endif
