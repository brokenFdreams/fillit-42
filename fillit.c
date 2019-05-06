/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/30 17:56:10 by fsinged          ###   ########.fr       */
=======
/*   Updated: 2019/05/05 19:43:44 by acalandr         ###   ########.fr       */
>>>>>>> 738e13a4a4ca8f14192a63d924cc41d404a5a52d
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

	/* add here reset # by steps from "isol" */
	return (map);
}

int 	is_isolate(char *map, int *mas, int mov[2], char *isol)
{
	int			count;
	int 		steps[4];
	int 		moves[2];
	int			*isol;          /* <- for steps of isolated */
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
			if (++count > 3 || (c = is_isolate(map, mas, moves, isol++)) == -1 || c + count > 3)		/* <- count > 3 - for miss first box wich is tetriminos */
				return (-1);
		}
		i++;
	}
	if(map[mas[0] + mov[0]] == '.')
	{
			/* isol =                 <- write steps here */
		map[mas[0] + mov[0]] = '#';		/* <- write # for isolated -> then reset by steps from "isol" */
	}
	return(count + c - 1);
}

int		is_suitable(char *map, char *cnt, int *mas)
{
	int 	mov[2];
	char	isol[15];
	int		i;
	int		c;

	ft_bzero(isol);							/* add in librari */
	if (map[mas[0] + cnt[0]] == '.' && map[mas[0] + cnt[1]] == '.'
	&& map[mas[0] + cnt[2]] == '.')
	{
		suite(map, cnt, mas);
		mov[0] = 0;
		mov[1] = 0;
		i = 0;
		while(i < 4)
		{
			if ((c = is_isolate(map, mas, mov, isol)) != -1)
				mas[2] += c;
			mov[0] = mov[1];
			if (i != 3)
				mov[1] = cnt[i];
			i++;
		}
		if (mas[1] * mas[1] - mas[2] - (cnt[3] - 65) < (mas[3] - (cnt[3] - 65)) * 4)
		{
			
			return(0);
		}
		return(1);
	}	
	return (0);
}

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
	while (map[mas[0]])
	{
		if (map[mas[0]] == '.' && is_suitable(map, (char*)tlist->content, mas))
		{
			pos = mas[0];
			isol = mas[2];
			mas[0] = 0;
<<<<<<< HEAD
			i = fill(map, tlist->next, mas);
			if (i == 1)
				return (1);
			mas[0] = pos;
=======
			if (fill(map, tlist->next, mas) == 1)
				return (1);
			mas[0] = pos;
			mas[2] = isol;
>>>>>>> 738e13a4a4ca8f14192a63d924cc41d404a5a52d
			map = reset_map(map, (char*)tlist->content, mas);
		}
		mas[0]++;
	}
	return (0);
}

/*
** mas[0] = position in map;
** mas[1] = width of map without \n;
** mas[2] = isolated
** mas[3] = list length - count of tetriminos
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
