/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:10:02 by hyalcink          #+#    #+#             */
/*   Updated: 2024/05/15 16:10:03 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_rgb_convert(t_map *map)
{
	map->frgb = create_trgb(0, map->f[0], map->f[1], map->f[2]);
	map->crgb = create_trgb(0, map->c[0], map->c[1], map->c[2]);
}
