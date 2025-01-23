/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:12:34 by sbozan            #+#    #+#             */
/*   Updated: 2024/05/15 21:12:35 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_zero_zero_extra(int i, int j, int map_start, t_map *main_s)
{
	int	len;

	len = ft_strlen_modded(main_s->file[i]);
	if ((i == map_start || i == main_s->map_infos.y + map_start - 1
			|| j == 0 || j == len - 1) && main_s->file[i][j] == '0')
		return (1);
	else if (i > map_start && i != main_s->map_infos.y + map_start - 1
		&& j > 0 && j != len - 1 && main_s->file[i][j] == '0')
	{
		if (main_s->file[i - 1][j] == ' ')
			return (1);
		if (main_s->file[i + 1][j] == ' ')
			return (1);
		if (main_s->file[i][j - 1] == ' ')
			return (1);
		if (main_s->file[i][j + 1] == ' ')
			return (1);
	}
	if (main_s->file[i][j] == '0' && i != map_start
			&& i != main_s->map_infos.y + map_start - 1)
		if (j > (int)ft_strlen_modded(main_s->file[i - 1]) - 1
			|| j > (int)ft_strlen_modded(main_s->file[i + 1]) - 1)
			return (1);
	return (0);
}

int	ft_zero_zero(char **map, t_map *main_s, int map_start)
{
	int	i;
	int	j;

	i = map_start;
	while (i < main_s->map_infos.y + map_start)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (ft_zero_zero_extra(i, j, map_start, main_s))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
