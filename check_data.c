/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:41:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 16:38:12 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_sign(int *mas, char *data, t_list **tlist)
{
	if (data[mas[3]] != '#' && data[mas[3]] != '.')
		ft_error();
	if (data[mas[3]] == '#')
	{
		if (mas[2] == 0)
			add_tetri(tlist, mas, data);
		else if (mas[2] == 4)
			ft_error();
		mas[2]++;
	}
}

/*
** mas[0] = y;
** mas[1] = x;
** mas[2] = count of #;
** mas[3] = position in data;
** mas[4] = count of tetro;
*/

void	i_need_place(int *mas, char *data, t_list **tlist)
{
	while (mas[1] < 4 && data[mas[3]])
	{
		check_sign(mas, data, tlist);
		mas[3]++;
		mas[1]++;
	}
}

void	check_data(char *data, t_list **tlist)
{
	int	mas[5];

	mas[3] = 0;
	mas[4] = 0;
	while (data[mas[3]])
	{
		mas[2] = 0;
		mas[0] = 0;
		while (mas[0] < 4 && data[mas[3]])
		{
			mas[1] = 0;
			i_need_place(mas, data, tlist);
			if (data[mas[3]] != '\n')
				ft_error();
			if (data[mas[3]])
				mas[3]++;
			mas[0]++;
		}
		if ((data[mas[3]] && data[mas[3]] != '\n') || mas[2] != 4
			|| (!data[mas[3] + 1] && data[mas[3]]))
			ft_error();
		if (data[mas[3]])
			mas[3]++;
		mas[4]++;
	}
}
