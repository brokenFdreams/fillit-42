/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:30:57 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/07 16:02:02 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_list_size(t_list *begin_list)
{
	t_list *list;

	list = begin_list;
	if (begin_list)
		return (1 + ft_list_size(list->next));
	return (0);
}

char	*fill_map(char *map, int width)
{
	int		i;
	char	*p;

	i = 0;
	p = map;
	while (i < width)
	{
		p = ft_memset(p, '.', width);
		p[width] = '\n';
		p += (width + 1);
		i++;
	}
	map[width * width + width] = '\0';
	return (map);
}

char	*create_map(t_list **tlist, int *width)
{
	char	*map;
	size_t	size;

	size = ft_list_size(*tlist) * 4;
	*width = ft_sqrt((int)size);
	size = *width * *width + *width;
	if (!(map = (char*)malloc(size + 1)))
		ft_error();
	map = fill_map(map, *width);
	scale_tetri(tlist, *width - 4);
	return (map);
}

void	scale_map(char **map, int *width, int scale)
{
	char	*temp;

	*width += scale;
	if (!(temp = (char*)malloc(*width * *width + *width + 1)))
		ft_error();
	temp = fill_map(temp, *width);
	ft_strdel(map);
	*map = temp;
}
