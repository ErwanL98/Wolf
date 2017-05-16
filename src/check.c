/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:58:46 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/16 17:52:04 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_check_map(char *map, t_parse *p)
{
	p->i = -1;
	p->test = NULL;
	p->count = 0;
	p->nb = 0;
	p->height = 0;
	((p->fd = open(map, O_RDONLY)) == -1) ? ft_error_file() : "";
	p->line = NULL;
	p->width = 0;
	while (get_next_line(p->fd, &p->line) == 1)
	{
		(p->test) ? ft_strdel(&p->test) : "";
		ft_check_line(p->line, &p->count);
		p->nb = ft_cw(p->line, ' ');
		if ((p->width != 0 && p->width != p->nb) || p->nb == 0)
			ft_error();
		p->width = p->nb;
		p->height++;
		p->test = ft_strdup(p->line);
		ft_strdel(&p->line);
	}
	ft_strdel(&p->line);
	(p->nb == 0) ? ft_error() : "";
	while (p->test[++p->i])
		(p->test[p->i] != '1' && p->test[p->i] != ' ') ? ft_error() : "";
	(p->test) ? ft_strdel(&p->test) : "";
}

void	ft_check_line(char *line, int *count)
{
	int		i;

	i = -1;
	if (*count == 0)
	{
		while (line[++i])
			(line[i] != ' ' && line[i] != '1') ? ft_error() : "";
	}
	else
	{
		while (line[++i])
			;
		(line[i - 1] != '1' || line[0] != '1') ? ft_error() : "";
	}
	*count += 1;
}

int		**ft_create_tab(char *map, t_parse parse)
{
	parse.split = NULL;
	parse.line = NULL;
	parse.tab = NULL;
	parse.y = 0;
	if ((parse.tab = (int **)malloc(sizeof(int *) * parse.height)) == NULL)
		ft_error();
	if ((parse.fd = open(map, O_RDONLY)) == -1)
		ft_error_file();
	while (get_next_line(parse.fd, &parse.line) == 1)
	{
		parse.split = ft_strsplit(parse.line, ' ');
		parse.x = -1;
		if ((parse.tab[parse.y] = (int *)malloc(sizeof(int) * \
														parse.width)) == NULL)
			ft_error();
		while (parse.split[++parse.x])
			parse.tab[parse.y][parse.x] = ft_atoi(parse.split[parse.x]);
		ft_tabdel(&parse.split);
		parse.y++;
		ft_strdel(&parse.line);
	}
	ft_strdel(&parse.line);
	return (parse.tab);
}
