/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:41:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/26 16:46:05 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

void	check_sign(int *mas, char *data, t_list **tlist)
{
	if (data[mas[3]] != '#' && data[mas[3]] != '.')
		ft_error();
	if (data[mas[3]] == '#')
	{
		if (mas[2] == 4)
			ft_error();
		if (mas[2] == 0)
			add_tetri(tlist, mas, data);
		if (mas[3] + 1 <= BUFF_SIZE && data[mas[3] + 1] == '#')
			mas[5]++;
		if (mas[3] - 1 >= 0 && data[mas[3] - 1] == '#')
			mas[5]++;
		if (mas[3] + 5 <= BUFF_SIZE && data[mas[3] + 5] == '#')
			mas[5]++;
		if (mas[3] - 5 >= 0 && data[mas[3] - 5] == '#')
			mas[5]++;
		/*if (!((mas[1] != 3 && data[mas[3] + 1] == '#') ||
			  (mas[0] != 3 && data[mas[3] + 5] == '#') ||
			  mas[2] == 3))
			ft_error();*/
		if (mas[5] > 8)
			ft_error();
		if (mas[2] == 3 && mas[5] < 6)
			ft_error();
		mas[2]++;
	}
}

/*
** mas[0] = i;
** mas[1] = j;
** mas[2] = count of #;
** mas[3] = position in data;
** mas[4] = count of tetro;
 * mas[5] = count of touch;
*/

void	check_data(char *data, t_list **tlist)
{
	int	mas[6];

	mas[3] = 0;
	mas[4] = 0;
	while (data && data[mas[3]])
	{
		mas[5] = 0;
		mas[2] = 0;
		mas[0] = 0;
		while (mas[0] < 4 && data[mas[3]])
		{
			mas[1] = 0;
			while (mas[1] < 4 && data[mas[3]])
			{
				check_sign(mas, data, tlist);
				mas[3]++;
				mas[1]++;
			}
			if (data[mas[3]] && data[mas[3]] != '\n')
				ft_error();
			mas[3]++;
			mas[0]++;
		}
		if ((data[mas[3]] && data[mas[3]] != '\n') || mas[2] != 4)
			ft_error();
		mas[3]++;
		mas[4]++;
	}
}
