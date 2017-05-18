/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initbase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:07:21 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 16:33:53 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_init_42(t_def *def)
{
	def->o_time = 0;
	def->time = 0;
	def->pos_x = 1.5;
	def->pos_y = 1.5;
	def->dir_x = 1;
	def->dir_y = 0;
	def->plane_x = 0;
	def->plane_y = 0.66;
	def->garg.pos_y = 7.5;
	def->garg.pos_x = 3.5;
}

void	ft_init_1(t_def *def)
{
	def->o_time = 0;
	def->time = 0;
	def->pos_x = 1.5;
	def->pos_y = 1.5;
	def->dir_x = 1;
	def->dir_y = 0;
	def->plane_x = 0;
	def->plane_y = 0.66;
	def->garg.pos_y = 7.5;
	def->garg.pos_x = 15.5;
}

void	ft_init_2(t_def *def)
{
	def->o_time = 0;
	def->time = 0;
	def->pos_x = 4.5;
	def->pos_y = 1.5;
	def->dir_x = 1;
	def->dir_y = 0;
	def->plane_x = 0;
	def->plane_y = 0.66;
	def->garg.pos_y = 1.5;
	def->garg.pos_x = 15.5;
}
