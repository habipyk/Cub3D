/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:59:45 by hyalcink          #+#    #+#             */
/*   Updated: 2024/05/15 15:59:47 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_move(t_data *data, int sign, double move_speed)
{
	double	x;
	double	y;

	x = data->player->pos_x;
	y = data->player->pos_y;
	if (sign == 1)
	{
		x += data->player->dir_x * move_speed;
		y += data->player->dir_y * move_speed;
	}
	else
	{
		x -= data->player->dir_x * move_speed;
		y -= data->player->dir_y * move_speed;
	}
	if (data->map[(int)y][(int)x] == '1')
	{
		return (1);
	}
	data->player->pos_x = x;
	data->player->pos_y = y;
	return (0);
}

void	calc_rot(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->dir_x;
	old_plane_x = data->player->plane_x;
	data->player->dir_x = data->player->dir_x * cos(rot_speed)
		- data->player->dir_y * sin(rot_speed);
	data->player->dir_y = old_dir_x * sin(rot_speed)
		+ data->player->dir_y * cos(rot_speed);
	data->player->plane_x = data->player->plane_x * cos(rot_speed)
		- data->player->plane_y * sin(rot_speed);
	data->player->plane_y = old_plane_x * sin(rot_speed)
		+ data->player->plane_y * cos(rot_speed);
}

int	calc_move_d(t_data *data, int sign, double move_speed)
{
	double	x;
	double	y;

	if (sign == 1)
	{
		x = data->player->pos_x + data->player->plane_x * move_speed;
		y = data->player->pos_y + data->player->plane_y * move_speed;
	}
	else
	{
		x = data->player->pos_x - data->player->plane_x * move_speed;
		y = data->player->pos_y - data->player->plane_y * move_speed;
	}
	if (data->map[(int)y][(int)x] == '1')
		return (1);
	data->player->pos_x = x;
	data->player->pos_y = y;
	return (0);
}
