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

char	*fill_map(char *map, int width)		/*width without \n */
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

	size  = ft_list_size(*tlist) * 4;
	*width = ft_sqrt((int)size);
	size = *width * *width + *width;
	if (!(map = (char*)malloc(size + 1)))
		ft_error();
	map = fill_map(map, *width);
	scale_tetri(tlist, 4, *width - 4);
	return(map);
}

void	scale_map(char **map, int *width, int scale)	/* width without \n */
{
	char	*temp;

	*width += scale;
	if (!(temp = ft_strnew(*width * *width + *width)))
		ft_error();
	temp = fill_map(temp, *width);
	ft_strdel(map);
	*map = temp;
}
