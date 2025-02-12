/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:13:14 by sbozan            #+#    #+#             */
/*   Updated: 2024/05/15 21:42:39 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_texture *text, t_ray *ray, t_player *player, int height)
{
	if (ray->side == 0)
		text->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		text->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	text->wall_x -= floor(text->wall_x);
	text->text_x = (int)(text->wall_x * (double)64);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		text->text_x = 64 - text->text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		text->text_x = 64 - text->text_x - 1;
	text->step = 1.0 * 64 / ray->line_height;
	text->tex_pos = (ray->draw_start - 100 - height / 2 + ray->line_height / 2)
		* text->step;
}

void	draw_picture(int x, t_data *data, t_ray *ray, t_texture *text)
{
	int		y;
	t_put	put;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		text->text_y = (int)text->tex_pos & (64 - 1);
		text->tex_pos += text->step;
		if (ray->side == 0 && ray->ray_dir_x < 0)
			text->color = image_color(text->text_x,
					text->text_y, &(data->walls[WEST]));
		if (ray->side == 0 && ray->ray_dir_x > 0)
			text->color = image_color(text->text_x,
					text->text_y, &(data->walls[EAST]));
		if (ray->side == 1 && ray->ray_dir_y < 0)
			text->color = image_color(text->text_x,
					text->text_y, &(data->walls[NORTH]));
		if (ray->side == 1 && ray->ray_dir_y > 0)
			text->color = image_color(text->text_x,
					text->text_y, &(data->walls[SOUTH]));
		put = (t_put){.x = x, .start = y, .end = y + 1, .color = text->color};
		put_image(&put, data->screen_image);
		y++;
	}
}

void	raycasting(t_data *data, t_win *win, t_player *player)
{
	int			x;
	t_ray		ray;
	t_texture	text;

	x = 0;
	while (x < win->width_screen)
	{
		init_ray(x, data, &ray);
		step_calc(player, &ray);
		dda(&ray, data->map);
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x);
		else
			ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y);
		ray.line_height = (int)(win->width_screen / ray.perp_wall_dist
				* 7 / 11);
		start_end_calc(&ray, win->height_screen);
		init_texture(&text, &ray, player, win->height_screen);
		draw_picture(x, data, &ray, &text);
		x++;
	}
}

void	mini_put(int units, t_put *put, t_image *img)
{
	int	i;

	i = 0;
	while (i < units)
	{
		put_image(put, img);
		put->x++;
		i++;
	}
}

void	init_map(t_data *data)
{
	mlx_clear_window(data->mlx, data->win->win_addres);
	put_cle_floo(data);
	raycasting(data, data->win, data->player);
	mlx_put_image_to_window(data->mlx, data->win->win_addres,
		data->screen_image->img_adress, 0, 0);
}
