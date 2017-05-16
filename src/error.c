/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:18:43 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/16 15:01:39 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_error(void)
{
	ft_putendl("Error map.");
	exit(1);
}

void	ft_error_file(void)
{
	perror("Error ");
	exit(1);
}

void	ft_sdl_error(void)
{
	ft_putstr("Error : ");
	ft_putstr(SDL_GetError());
	ft_putchar('\n');
	SDL_Quit();
	exit(1);
}
