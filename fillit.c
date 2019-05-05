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

int 	is_isolate(char *map, int *mas, int mov[2])
{
	int			count;
	int 		steps[4];
	int 		moves[2];
	int			i;
	int 		c;

	steps[0] = mas[0] + mov[0] + 1;
	steps[1] = mas[0] + mov[0] - 1;
	steps[2] = mas[0] + mov[0] + mas[1] + 1;
	steps[3] = mas[0] + mov[0] - mas[1] - 1;
	i = 0;
	c = 0;
	count = 0;
	while (i < 4)
	{
		if (steps[i] != mas[0] + mov[1]	&& steps[i] < BUFF_SIZE	&& steps[i] >= 0 && map[steps[i]] == '.')
		{
			moves[0] = steps[i] - mas[0];
			moves[1] = mov[0];
			if (++count > 3 || (c = is_isolate(map, mas, moves)) == -1 || c + count > 3)
				return (-1);
		}
		i++;
	}
	return(count + c);
}

int		is_suitable(char *map, char *cnt, int *mas)
{
	int i;
	int mov[2];

	if (map[mas[0] + cnt[0]] == '.' && map[mas[0] + cnt[1]] == '.'
	&& map[mas[0] + cnt[2]] == '.')
	{
		suite(map, cnt, mas);
		i = 0;
		mov[0] = 0;
		mov[1] = 0;
		while(i < 4)
		{
			is_isolate(map, mas, mov);
			mov[0] = mov[1];
			if (i != 3)
				mov[1] = cnt[i];
			i++;
		}
		return(1);
	}
	return (0);
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
	int		pos;
	char	*cont;
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
		if (map[mas[0]] == '.' && is_suitable(map, (char*)tlist->content, mas))
		{
			pos = mas[0];
			isol = mas[2];
			mas[0] = 0;
			if (fill(map, tlist->next, mas) == 1) /* cut */
				return (1);
			mas[0] = pos;
			mas[2] = isol;
			map = reset_map(map, (char*)tlist->content, mas);
		}
		if (mas[1] * mas[1] - mas[2] - (cont[3] - 64) * 4 < (ft_list_size(tlist) - 1) * 4)
			return(0);
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
