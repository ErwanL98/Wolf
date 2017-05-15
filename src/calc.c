/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:15:54 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/15 12:46:56 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_check_wall(t_def def, t_calc *calc)
{
	ft_init_calc(calc);
	ft_set(calc);
	while (calc->hit == 0)
	{
		if (calc->s_dist_x < calc->s_dist_y)
		{
			calc->s_dist_x += calc->d_dist_x;
			calc->map_x += calc->step_x;
			calc->side = 0;
		}
		else
		{
			calc->s_dist_y += calc->d_dist_y;
			calc->map_y += calc->step_y;
			calc->side = 1;
		}
		calc->hit = (def.tab[calc->map_y][calc->map_x] > 0) ? 1 : calc->hit;
	}
	calc->wall_dist = (calc->side == 0) ? (calc->map_x - calc->ray_pos_x + \
	(1 - calc->step_x) / 2) / calc->ray_dir_x : (calc->map_y - calc->ray_pos_y \
				+ (1 - calc->step_y) / 2) / calc->ray_dir_y;
}

void	ft_set(t_calc *calc)
{
	if (calc->ray_dir_x < 0)
	{
		calc->step_x = -1;
		calc->s_dist_x = (calc->ray_pos_x - calc->map_x) * calc->d_dist_x;
	}
	else
	{
		calc->step_x = 1;
		calc->s_dist_x = (calc->map_x + 1.0 - calc->ray_pos_x) * calc->d_dist_x;
	}
	if (calc->ray_dir_y < 0)
	{
		calc->step_y = -1;
		calc->s_dist_y = (calc->ray_pos_y - calc->map_y) * calc->d_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->s_dist_y = (calc->map_y + 1.0 - calc->ray_pos_y) * calc->d_dist_y;
	}
}

void	ft_loop(t_def def, t_sdl *sdl)
{
	int		x;
	t_calc	calc;

	x = -1;
	while (++x < WIDTH)
	{
		calc.camera_x = 2 * x / (double)WIDTH - 1;
		calc.ray_pos_x = def.pos_x;
		calc.ray_pos_y = def.pos_y;
		calc.ray_dir_x = def.dir_x + def.plane_x * calc.camera_x;
		calc.ray_dir_y = def.dir_y + def.plane_y * calc.camera_x;
		ft_check_wall(def, &calc);
		ft_draw(x, calc, sdl, def);
	}
}
