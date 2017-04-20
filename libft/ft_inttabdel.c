/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:24:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/04/20 14:27:14 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_inttabdel(int	***tab)
{
	int		**new;
	int		i;

	new = *tab;
	if (new != NULL)
	{
		i = 0;
		while (new[i])
			free(new[i++]);
		free(new);
		*tab = NULL;
	}
}
