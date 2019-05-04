/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 16:40:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*suite(char *map, char *cnt, int *mas)
{
	map[mas[0]] = cnt[3];
	map[mas[0] + cnt[0]] = cnt[3];
	map[mas[0] + cnt[1]] = cnt[3];
	map[mas[0] + cnt[2]] = cnt[3];
	return (map);
}

char	*reset_map(char *map, char *cnt, int *mas)
{
	map[mas[0]] = '.';
	map[mas[0] + cnt[0]] = '.';
	map[mas[0] + cnt[1]] = '.';
	map[mas[0] + cnt[2]] = '.';
	return (map);
}

int		is_suitable(char *map, char *cnt, int *mas)
{
	return (map[mas[0] + cnt[0]] == '.' && map[mas[0] + cnt[1]] == '.'
			&& map[mas[0] + cnt[2]] == '.');
}

int 	is_isolate(char *map, int *mas, int step, int prevst)
{
	static int	count = 0;
	int 		steps[4];
	int			i;

	if (!step)
		count = 0;
	steps[0] = mas[0] + 1 + step;
	steps[1] = mas[0] - 1 + step;
	steps[2] = mas[0] + mas[1] + 1 + step;
	steps[3] = mas[0] - mas[1] - 1 + step;
	i = 0;
	while (i < 4)
	{
		if (steps[i] != mas[0] + prevst && steps[i] < BUFF_SIZE	&& steps[i] >= 0 && map[steps[i]] == '.') {
			if (++count > 2 || !is_isolate(map, mas, steps[i] - mas[0], step))
				return (0);
		}
		i++;
	}
	map[mas[0] + step] = '#';
	mas[2]++;
	return(1);
}

/*		mas[0] step pstep
** .#..	0	   0	0
** .#..	0 	   5	0
** .#..	0 	   10	5
*/

/*		mas[0] step pstep
** .#..	0	   0	0
** .#..	0 	   5	0
** ##..	0 	   10	5
*/

int		fill(char *map, t_list *tlist, int *mas)
{
	int pos;
	char oldmap[BUFF_SIZE];
	char *cont;
	int 	isol;

	if (!tlist)
	{
		ft_putstr(map);
		ft_strdel(&map);
		return (1);
	}
	cont = (char*)tlist->content;
	while (map[mas[0]])	/* cut */
	{
		if (map[mas[0]] == '.' && !is_isolate(map, mas, 0, 0)
			&& is_suitable(map,	(char*)tlist->content, mas))
		{
			pos = mas[0];
			ft_memmove(oldmap, map, mas[1] * mas[1] + mas[1]);	/* time!!! */
			isol = mas[2];
			map = suite(map, (char*)tlist->content, mas);
			mas[0] = 0;
			if (mas[1] * mas[1] - mas[2] - (cont[3] - 64) * 4 > (ft_list_size(tlist) - 1) * 4)
				if (fill(map, tlist->next, mas) == 1) /* cut */
					return (1);
			mas[0] = pos;
			mas[2] = isol;
			map = ft_memmove(map, oldmap, mas[1] * mas[1] + mas[1]); /* time!!! */
		}
		mas[0]++;
	}
	return (0);
}

/*
** mas[0] = position in map;
** mas[1] = width of map without \n;
** mas[2] = isolated
*/

void	fillit(t_list **tlist)
{
	char	*map;
	int		mas[3];

	mas[0] = 0;
	mas[1] = 0;
	mas[2] = 0;
	map = create_map(tlist, &mas[1]);
	while (fill(map, *tlist, mas) != 1)
	{
		scale_tetri(tlist, mas[1], 1);
		scale_map(&map, &mas[1], 1);
		mas[0] = 0;
	}
}
