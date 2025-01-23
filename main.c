/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:56:03 by hyalcink          #+#    #+#             */
/*   Updated: 2024/05/15 16:09:02 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_data *data)
{
	keyboard(data);
	init_map(data);
	return (0);
}

int	main(int ac, char *arv[])
{
	t_data	data;
	t_map	map;

	if (ac != 2)
	{
		printf("Missing Arguments !\n");
		return (0);
	}
	check_main(arv, &map);
	init_data(&map, &data);
	init_map(&data);
	mlx_hook(data.win->win_addres, 2, 0, key_press, &data);
	mlx_hook(data.win->win_addres, 3, 0, key_release, &data);
	mlx_hook(data.win->win_addres, 17, 1L << 2, ft_exit, NULL);
	mlx_loop_hook(data.mlx, loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
