/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/07 16:01:42 by fsinged          ###   ########.fr       */
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
	int	pos;

	if (!tlist)
	{
		ft_putstr(map);
		ft_strdel(&map);
		return (1);
	}
	while (map[mas[0]])
	{
		if (map[mas[0]] == '.' && is_suitable(map, (char*)tlist->content, mas))
		{
			suite(map, (char*)tlist->content, mas);
			pos = mas[0];
			mas[0] = 0;
			if (fill(map, tlist->next, mas) == 1)
				return (1);
			mas[0] = pos;
			map = reset_map(map, (char*)tlist->content, mas);
		}
		mas[0]++;
	}
	return (0);
}

/*
** mas[0] = position on map;
** mas[1] = width of map without \n;
*/

void	fillit(t_list **tlist)
{
	char	*map;
	int		mas[4];

	mas[0] = 0;
	mas[1] = 0;
	map = create_map(tlist, &mas[1]);
	while (fill(map, *tlist, mas) != 1)
	{
		scale_tetri(tlist, 1);
		scale_map(&map, &mas[1], 1);
		mas[0] = 0;
	}
}
