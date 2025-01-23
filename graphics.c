/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:11:58 by sbozan            #+#    #+#             */
/*   Updated: 2024/05/15 21:11:59 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color, t_image *img)
{
	char	*dst;

	dst = img->buffer + (y * img->size_line + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}

void	put_image(t_put *put, t_image *img)
{
	int	start;

	start = put->start;
	while (start < put->end)
	{
		my_mlx_pixel_put(put->x, start, put->color, img);
		start++;
	}
}
