//
// Created by Abbie Calandra on 2019-04-29.
//

#include "../includes/fillit.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *list;

	list = begin_list;
	if (begin_list)
		return (1 + ft_list_size(list->next));
	return (0);
}

char	*create_map(t_list **tlist, int *width)
{
	char	*map;
	size_t	size;

	size  = ft_list_size(*tlist) * 4;
	if (!(map = ft_strnew(size)))
		ft_error();
	*width = ft_sqrt((int)size);
	scale_tetri(tlist, *width - 4);
	return(map);
}

void	scale_map(char **map, int *width, int scale)
{
	char	*temp;

	*width += scale;
	if (!(temp = ft_strnew(*width * *width)))
		ft_error();
	ft_strdel(map);
	*map = temp;
}
