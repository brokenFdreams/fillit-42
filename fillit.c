/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/07 15:18:29 by fsinged          ###   ########.fr       */
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
	int count;

	if (map[mas[0] + cnt[0]] == '.' && map[mas[0] + cnt[1]] == '.'
			&& map[mas[0] + cnt[2]] == '.')
	{
		if (mas[3] < 5)
		{
			suite(map, cnt, mas);
			count = is_isolated(map, cnt, mas);
			if (count == -1 || count + mas[2] > mas[3])
			{
				reset_isol(map, cnt, mas);
				reset_map(map, cnt, mas);
				return (-1);
			}
			return (count);
		}
		return (0);
	}
	return (-1);
}

int		fill(char *map, t_list *tlist, int *mas)
{
	int	pos;
	int isol;
	int i;

	if (!tlist)
	{
		ft_setchar(map);
		ft_putstr(map);
		ft_strdel(&map);
		return (1);
	}
	while (map[mas[0]])
	{
		if (map[mas[0]] == '.' &&
			(i = is_suitable(map, (char*)tlist->content, mas)) != -1)
		{
			isol = mas[2];
			pos = mas[0];
			mas[0] = 0;
			mas[2] += i;
			if (fill(map, tlist->next, mas) == 1)
				return (1);
			mas[0] = pos;
			mas[2] = isol;
			reset_isol(map, (char*)tlist->content, mas);
			map = reset_map(map, (char*)tlist->content, mas);
		}
		mas[0]++;
	}
	return (0);
}

/*
** mas[0] = position on map;
** mas[1] = width of map without \n;
** mas[2] = count of isolated;
** mas[3] = all isolated;
*/

void	fillit(t_list **tlist)
{
	char	*map;
	int		mas[4];
	int		list_size;

	mas[0] = 0;
	mas[1] = 0;
	list_size  = ft_list_size(*tlist) * 4;
	map = create_map(tlist, &mas[1]);
	mas[3] = mas[1] * mas[1] - list_size;;
	while (fill(map, *tlist, mas) != 1)
	{
		scale_tetri(tlist, mas[1], 1);
		scale_map(&map, &mas[1], 1);
		mas[3] = mas[1] * mas[1] - list_size;
		mas[2] = 0;
		mas[0] = 0;
	}
}
