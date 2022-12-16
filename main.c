/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:31:34 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/16 16:45:03 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static int deal_key(int key, void *data)
// {
//     (void)data;
//     printf("%d", key);
//     return (0);
// }

void	init_struct(fdf *data)
{
	data->height = 0;
	data->width = 0;
}

void	free_tab(fdf *data)
{
	int		index;

	index = 0;
	while (index <= data->height)
		free(data->z_matrix[index++]);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
		return (0);
	data = (fdf*)malloc(sizeof(fdf));
	init_struct(data);
	read_file(argv[1], data);
	
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	free_tab(data);
	free(data->z_matrix);
	free(data);
	return (0);
}
