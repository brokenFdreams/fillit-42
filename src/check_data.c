/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:41:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/25 17:18:11 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		check_sign(int k, char *data, int count, int i, int j)
{
	if (data[count] != '#' && data[count] != '.')
		ft_error();
	if (data[count] == '#')
	{
		if (k == 4)
			ft_error();
		if (!((j != 0 && data[count - 1] == '#') ||
			(j != 3 && data[count + 1] == '#') ||
			(i != 0 && data[count - 5] == '#') ||
			  (i != 3 && data[count + 5] == '#')))
		{
			printf("there");
			printf("data[%d] = %c\n", count, data[count]);
			printf("data[%d] = %c, data[%d] = %c\n", count - 1, data[count - 1], \
				   count + 1, data[count + 1]);
			printf("data[%d] = %c, data[%d] = %c\n", count - 4, data[count - 4], \
				   count + 4, data[count + 4]);
			ft_error();
		}
		k++;
	}
	return (k);
}

void	check_data(char *data)
{
	int i;
	int j;
	int k;
	int count;

	count = 0;
	while (data && data[count])
	{
		k = 0;
		i = 0;
		while (i++ < 4 && data[count])
		{
			j = 0;
			while (j++ < 4 && data[count])
			{
				k = check_sign(k, data, count, i - 1, j - 1);
				count++;
			}
			if (data[count] && data[count] != '\n')
				ft_error();
			count++;
		}
		if (data[count] && data[count] != '\n')
			ft_error();
		count++;
	}
}
