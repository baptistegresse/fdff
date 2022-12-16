/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:30:47 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/16 17:34:08 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../fdf.h"

void	get_height_width(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (data->width == 0)
			data->width = ft_wordcount(line, ' ');
		free(line);
		if (!line) 
			break ;
		data->height++;
	}
	close(fd);
}


void	allocated_matrix(fdf *data)
{
	int		index;
		
	index = 0;
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (index <= data->height)
	{
		data->z_matrix[index] = malloc(sizeof(int) * ((data->width) + 1));
		index++;
	}
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		index;

	nums = ft_split(line, ' ');
	index = 0;
	while (nums[index])
	{
		z_line[index] = ft_atoi(nums[index]);
		free(nums[index]);
		index++;
	}
	free(nums);
}

void	browse_fill_matrix(char *file_name, fdf *data)
{
	int		fd;
	int		index;
	char	*line;

	index = 0;
	fd = open(file_name, O_RDONLY);
	while (index < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[index++], line);
		free(line);
		if (!line)
			break ;
	}
	close(fd);
}

void	read_file(char *file_name, fdf *data)
{
	get_height_width(file_name, data);
	allocated_matrix(data);
	browse_fill_matrix(file_name, data);
}
