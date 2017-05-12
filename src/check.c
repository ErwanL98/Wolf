/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:47:38 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/12 15:07:56 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_check_error(char *av, t_parse *parse)
{
	parse->line = NULL;
	parse->height = 0;
	parse->nb = 0;
	if ((parse->fd = open(av, O_RDONLY)) == -1)
		ft_error_file();
	ft_check_error2(parse);
	if (parse->nb == 0)
		ft_error();
	if ((close(parse->fd)) == -1)
		ft_error_file();
}

void	ft_check_error2(t_parse *parse)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	parse->width = 0;
	while (get_next_line(parse->fd, &parse->line) == 1)
	{
		if (str)
			ft_strdel(&str);
		ft_check_valid(parse->line);
		parse->nb = ft_cw(parse->line, ' ');
		if ((parse->width != 0 && parse->nb != parse->width) || parse->nb == 0)
			ft_error();
		parse->width = parse->nb;
		parse->height++;
		str = (parse->line != NULL) ? ft_strdup(parse->line) : str;
		ft_strdel(&parse->line);
	}
	if (str)
	{
		while (str[i])
			(str[i] == '0') ? ft_error() : i++;
		ft_strdel(&str);
	}
}

int		**ft_create_map(char *av, t_parse parse)
{
	int		**tab;

	parse.split = NULL;
	tab = NULL;
	if ((parse.fd = open(av, O_RDONLY)) == -1)
		ft_error_file();
	parse.y = 0;
	tab = ft_assign(&parse);
	if ((close(parse.fd)) == -1)
		ft_error_file();
	return (tab);
}

int		**ft_assign(t_parse *parse)
{
	int		**tab;

	tab = NULL;
	if ((tab = (int **)malloc(sizeof(int *) * (parse->height + 1))) == NULL)
		ft_error();
	while (get_next_line(parse->fd, &parse->line) == 1)
	{
		if ((tab[parse->y] = (int *)malloc(sizeof(int) * parse->width)) == NULL)
			ft_error();
		parse->split = ft_strsplit(parse->line, ' ');
		parse->x = -1;
		while (parse->split[++parse->x])
			tab[parse->y][parse->x] = ft_atoi(parse->split[parse->x]);
		ft_tabdel(&parse->split);
		parse->y++;
		ft_strdel(&parse->line);
	}
	tab[parse->y] = NULL;
	return (tab);
}

void	ft_check_valid(char *line)
{
	static int	i = 0;
	int			y;
	char		**split;

	y = -1;
	split = NULL;
	split = ft_strsplit(line, ' ');
	if (split != NULL)
	{
		while (split[++y])
			(i == 0 && ft_atoi(split[y]) <= 0) ? ft_error() : "";
		if (ft_atoi(split[y - 1]) <= 0 || ft_atoi(split[0]) <= 0)
			ft_error();
		i++;
	}
	ft_tabdel(&split);
}
