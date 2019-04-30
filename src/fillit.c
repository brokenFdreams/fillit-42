/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/29 17:11:55 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

/*
** yx[0] = copy y;
** yx[1] = copy x;
** yx[2] = copy position in map;
*/
void	change_mas(int *mas, int *yx)
{
	/*ft_putnbr(2);*/
	if (yx[1] < mas[3] - 1)
	{
		yx[1] += 1;
		yx[2] += 1;
		mas[1] = yx[1];
		mas[2] = yx[2];
	}
	else
	{
		yx[0] += 1;
		yx[1] = 0;
		yx[2] += 1;
		mas[0] = yx[0];
		mas[1] = 0;
		mas[2] = yx[2];
	}
}

char	*suite(char *map, char *cnt, int *mas)
{
	/*ft_putnbr(3);*/
	map[mas[2]] = cnt[3];
	map[mas[2] + cnt[0]] = cnt[3];
	map[mas[2] + cnt[1]] = cnt[3];
	map[mas[2] + cnt[2]] = cnt[3];
	return (map);
}

int		is_suitable(char *map, char *cnt, int *mas)
{
	return (map[mas[2] + cnt[0]] == '.' && map[mas[2] + cnt[1]] == '.'
			&& map[mas[2] + cnt[2]] == '.');
}

int		fill(char *map, t_list *tlist, int *mas)
{
	int yx[3];
	int i;

	if(!tlist)
	{
		ft_putstr(map);
		return (1);
	}
	while (mas[0] < mas[3])
	{
		if (mas[1] == mas[3])
			mas[1] = 0;
		while (mas[1] < mas[3])
		{
			if (map[mas[2]] == '.' && is_suitable(map,
				(char*)tlist->content, mas))
			{
				yx[0] = mas[0];
				yx[1] = mas[1];
				yx[2] = mas[2];
				map = suite(map, (char*)tlist->content, mas);
				i = fill(map, tlist->next, mas);
				if (i == 0)
					return (-1);
				else if (i == -1)
					change_mas(mas, yx);
				else if (i == 1)
					return (1);
			}
			else
			{
				mas[1]++;
				mas[2]++;
			}
		}
		mas[0]++;
		mas[2]++;
	}
	return (0);
}

/*
** mas[0] = y;
** mas[1] = x;
** mas[2] = position in map;
** mas[3] = width of map;
*/

void	fillit(t_list **tlist)
{
	char	*map;
	int		i;
	int		mas[4];
	int		yx[3];

	mas[0] = 0;
	mas[1] = 0;
	mas[2] = 0;
	mas[3] = 0;
	yx[0] = 0;
	yx[1] = 0;
	yx[2] = 0;
	map = create_map(tlist, &mas[3]);			/* width - mas[3] - without \n */
	while ((i = fill(map, *tlist, mas)) != 1)
	{
		/*ft_putstr("i = ");
		ft_putnbr(i);
		ft_putchar('\n');*/
		if (i == 0)
		{
			scale_tetri(tlist, mas[3], 1);
			scale_map(&map, &mas[3], 1);
			yx[0] = 0;
			yx[1] = 0;
			yx[2] = 0;
			mas[0] = 0;
			mas[1] = 0;
			mas[2] = 0;
		}
		if (i == -1)
			change_mas(mas, yx);
	}
}
