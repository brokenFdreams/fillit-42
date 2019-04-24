/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:41:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/24 16:31:45 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	check_data(char *data)
{
	int i;
	int j;
	int k;

	while (data && *data)
	{
		k = 0;
		i = 0;
		while (i < 4 && data)
		{
			j = 0;
			while (j < 4 && data)
			{
				if (*data != '#' && *data != '.')
					ft_error();
				if (*data == '#')
				{
					if (k == 4)
						ft_error();
					k++;
				}
				data++;
				j++;
			}
			if (data && *data != '\n')
				ft_error();
			data++;
			i++;
		}
		if (data && *data != '\n' && *data != '\0')
			ft_error();
		data++;
	}
}
