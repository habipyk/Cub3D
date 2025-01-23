/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:11:44 by sbozan            #+#    #+#             */
/*   Updated: 2024/05/15 21:11:45 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_full_file(int fd, char **full_file, char *file_name)
{
	int	i;

	i = 0;
	fd = open(file_name, O_RDWR);
	full_file[0] = get_next_line(fd);
	while (full_file[i])
		full_file[++i] = get_next_line(fd);
	close(fd);
}

char	**ft_read_map(char *file_name)
{
	char	**full_file;
	int		line_count;
	int		fd;
	char	*temp;

	fd = open(file_name, O_RDWR);
	temp = get_next_line(fd);
	line_count = 1;
	while (temp)
	{
		free(temp);
		line_count++;
		temp = get_next_line(fd);
	}
	if (line_count < 9)
		ft_error(0);
	full_file = malloc(sizeof(char *) * (line_count + 1));
	close(fd);
	ft_fill_full_file(fd, full_file, file_name);
	free(temp);
	return (full_file);
}
