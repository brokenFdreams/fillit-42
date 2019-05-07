/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolated.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:31:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/07 15:11:53 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_point(char *map, int point, int *mas)
{
	if (point > 0 && map[point] == '#')
	{
		map[point] = '.';
		reset_point(map, point + 1, mas);
		reset_point(map, point - 1, mas);
		reset_point(map, point + mas[1] + 1, mas);
		reset_point(map, point + mas[1] - 1, mas);
	}
	else if (point > 0 && map[point] >= 'A' &&
			 map[point] <= 'Z')
	{
		reset_point(map, point + 1, mas);
		reset_point(map, point - 1, mas);
		reset_point(map, point + mas[1] + 1, mas);
		reset_point(map, point + mas[1] - 1, mas);
	}
}

void	reset_isol(char *map, char *cnt, int *mas)
{
	reset_point(map, mas[0], mas);
	reset_point(map, mas[0] + cnt[0], mas);
	reset_point(map, mas[0] + cnt[1], mas);
	reset_point(map, mas[0] + cnt[2], mas);
}

int	is_isol_point(char *map, int pos, int *mas, int c)
{
	int	points[4];
	int i;
	int k;

	points[0] = pos + 1;
	points[1] = pos - 1;
	points[2] = pos + mas[1] + 1;
	points[3] = pos + mas[1] - 1;
	i = 0;
	while (i < 4)
	{
		if (points[i] >= 0 && map[points[i]] == '.')
		{
			if (c >= 3)
				return (-1);
			map[points[i]] = '#';
			c++;
			k = is_isol_point(map, points[i], mas, c);
			if (c + k > 3 || k == -1)
			{
				map[points[i]] = '.';
				return (-1);
			}
		}
		i++;
	}
	return (c);
}

int	is_isol(char *map, int pos, int *mas)
{
	int points[4];
	int i;
	int k;
	int count;

	points[0] = pos + 1;
	points[1] = pos - 1;
	points[2] = pos + mas[1] + 1;
	points[3] = pos + mas[1] - 1;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (points[i] >= 0 && map[points[0]] == '.')
		{
			map[points[i]] = '#';
			k = is_isol_point(map, points[0], mas, 1);
			if (k != -1)
				count += k;
			else
				map[points[i]] = '.';
		}
		i++;
	}
	return (count);
}

int	is_isolated(char *map, char *cnt, int *mas)
{
	int count;
	int k;
	int i;

	count = 0;
	k = is_isol(map, mas[0], mas);
	if (k == -1)
		reset_point(map, mas[0], mas);
	else
		count += k;
	i = 0;
	while (i < 3)
	{
		k = is_isol(map, mas[0] + cnt[i], mas);
		if (k == -1)
			reset_point(map, mas[0] + cnt[i], mas);
		else
			count += k;
		i++;
	}
	if (count + mas[2] > mas[3])
	{
		reset_isol(map, cnt, mas);
		return (-1);
	}
	return (count);
}
