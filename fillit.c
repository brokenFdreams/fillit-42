/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 16:12:07 by fsinged          ###   ########.fr       */
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

int		fill(char *map, t_list *tlist, int *mas)
{
	int pos;
	int i;

	if(!tlist)
	{
		ft_putstr(map);
		return (1);
	}
	while (map[mas[0]])
	{
		if (map[mas[0]] == '.' && is_suitable(map,
			(char*)tlist->content, mas))
		{
			pos = mas[0];
			map = suite(map, (char*)tlist->content, mas);
			mas[0] = 0;
			i = fill(map, tlist->next, mas);
			mas[0] = pos;
				map = reset_map(map, (char*)tlist->content, mas);
			if (i == 1)
				return (1);
		}
		mas[0]++;
	}
	return (0);
}

/*
** mas[0] = position in map;
** mas[1] = width of map without \n;
*/

void	fillit(t_list **tlist)
{
	char	*map;
	int		i;
	int		mas[2];
	int		pos;

	mas[0] = 0;
	mas[1] = 0;
	pos = 0;
	map = create_map(tlist, &mas[1]);
	while ((i = fill(map, *tlist, mas)) != 1)
		if (i == 0)
		{
			scale_tetri(tlist, mas[1], 1);
			scale_map(&map, &mas[1], 1);
			mas[0] = 0;
			pos = 0;
		}
		else if (i == -1)
		{
			pos += 1;
			mas[0] = pos;
		}
}
