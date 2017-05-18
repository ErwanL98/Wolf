/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:49:31 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 15:20:03 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_event(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event_game))
	{
		if (sdl->event_game.type == SDL_QUIT)
			sdl->keep_game = 0;
		if (sdl->event_game.type == SDL_KEYDOWN)
			sdl->in.key[sdl->event_game.key.keysym.scancode] = 1;
		else if (sdl->event_game.type == SDL_KEYUP)
			sdl->in.key[sdl->event_game.key.keysym.scancode] = 0;
		if (sdl->event_game.type == SDL_MOUSEBUTTONDOWN)
			sdl->in.button[sdl->event_game.button.button] = 1;
		else if (sdl->event_game.type == SDL_MOUSEBUTTONUP)
			sdl->in.button[sdl->event_game.button.button] = 0;
		if (sdl->event_game.type == SDL_MOUSEMOTION)
		{
			sdl->in.x_rel += sdl->event_game.motion.xrel;
			sdl->in.y_rel += sdl->event_game.motion.yrel;
		}
	}
}

void	ft_move_f(t_sdl *sdl, t_def *def)
{
	def->garg.test_x = def->pos_x;
	def->garg.test_y = def->pos_y;
	if (sdl->in.key[SDL_SCANCODE_W])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x + def->dir_x * \
					def->m_speed)] <= 0)
		{
			def->garg.test_x = def->pos_x + def->dir_x * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_x += def->dir_x * def->m_speed;
		}
		if (def->tab[(int)(def->pos_y + def->dir_y * \
					def->m_speed)][(int)def->pos_x] <= 0)
		{
			def->garg.test_y = def->pos_y + def->dir_y * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_y += def->dir_y * def->m_speed;
		}
	}
	ft_move_b(sdl, def);
}

void	ft_move_b(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_S])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x - def->dir_x * \
				def->m_speed)] <= 0)
		{
			def->garg.test_x = def->pos_x - def->dir_x * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_x -= def->dir_x * def->m_speed;
		}
		if (def->tab[(int)(def->pos_y - def->dir_y * \
					def->m_speed)][(int)def->pos_x] <= 0)
		{
			def->garg.test_y = def->pos_y - def->dir_y * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_y -= def->dir_y * def->m_speed;
		}
	}
	ft_move_l(sdl, def);
}

void	ft_move_l(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_A])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x - def->plane_x * \
					def->m_speed)] <= 0)
		{
			def->garg.test_x = def->pos_x - def->plane_x * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_x -= def->plane_x * def->m_speed;
		}
		if (def->tab[(int)(def->pos_y - def->plane_y * \
					def->m_speed)][(int)def->pos_x] <= 0)
		{
			def->garg.test_y = def->pos_x - def->plane_y * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_y -= def->plane_y * def->m_speed;
		}
	}
	ft_move_r(sdl, def);
}

void	ft_move_r(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_D])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x + def->plane_x * \
					def->m_speed)] <= 0)
		{
			def->garg.test_x = def->pos_x + def->plane_x * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_x += def->plane_x * def->m_speed;
		}
		if (def->tab[(int)(def->pos_y + def->plane_y * \
					def->m_speed)][(int)def->pos_x] <= 0)
		{
			def->garg.test_y = def->pos_x + def->plane_y * def->m_speed;
			def->garg.dist = sqrt(pow(def->garg.pos_x - def->garg.test_x, 2) + \
					pow(def->garg.pos_y - def->garg.test_y, 2));
			if (def->garg.dist > 0.2)
				def->pos_y += def->plane_y * def->m_speed;
		}
	}
	ft_cam_r(sdl, def);
}
