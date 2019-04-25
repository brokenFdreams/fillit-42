/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:41:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/25 16:11:24 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_sign(int k, char c, int flag)
{
	if (flag == 1)
	{
		if (c != '#' && c != '.')
			ft_error();
		if (c == '#')
		{
			if (k == 4)
				ft_error();
			k++;
		}
	}
	else if (c == '\n' || c == '\0')
		return (-1);
	return (k);
}

void	check_data(char *data)
{
	int i;
	int j;
	int k;

	while (data && *data)
	{
		k = 0;
		i = 0;
		while (i++ < 4 && data)
		{
			j = 0;
			while (j++ < 4 && data)
			{
				k = check_sign(k, *data, 1);
				data++;
			}
			if (data && check_sign(k, *data, 0) != -1)
				ft_error();
			data++;
		}
		if (data && check_sign(k, *data, 0) != -1)
			ft_error();
		data++;
	}
}
