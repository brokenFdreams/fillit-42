//
// Created by Abbie Calandra on 2019-04-28.
//

#include "fillit.h"

void	ft_list_push_back(t_list **begin_list, char	*sar)
{
	t_list *list;

	if ((list = *begin_list))
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(sar, 4 * sizeof(char));
	}
	else
		*begin_list = ft_lstnew(sar, 4 * sizeof(char));
}

int		count_touch(const char *data, int k, int j)
{
	int count;

	count = 0;
	if (j == 1 || j == 5)
		count++;
	else if (j + 1 == 5 && data[k + 5] == '#')
		count++;
	else if (j + 1 == 5 && data[k - 1] == '#')
		count++;
	if (k != 0 && (k + j) == 5)
		count++;
	return(count);
}

void	add_tetri(t_list **tlist, int *mas, const char *data)
{
	int		i;
	int 	j;
	int		count;
	char	sar[4];

	i = 0;
	j = 1;
	count = 0;
	while (i < 3)
	{
		while (data[mas[3] + j] != '#')
			j++;
		if (i - 1 >= 0 && (j - sar[i - 1] == 2 || j - sar[i - 1] >= 6))
			ft_error();
		else if (i == 0 && (j == 2 || j >= 6))
			ft_error();
		if (i == 0)
			count += count_touch(data + mas[3], 0, j);
		else
			count += count_touch(data + mas[3], sar[i - 1], j - sar[i - 1]);
		sar[i++] = j++;
	}
	count < 3 ? ft_error() : NULL;
	sar[3] = 'A' + mas[4];
	ft_list_push_back(tlist, sar);
}

void	scale_tetri(t_list **tlist, int width, int scale)
{
	t_list	*list;
	char 	*sar;
	int		i;

	width++;
	list = *tlist;
	while (list)
	{
		sar = list->content;
		i = 0;
		while (i < 3)
		{
			if ((i == 0 && sar[i] != 1)
			|| (i - 1 >= 0 && sar[i] - sar[i - 1] != 1))
			{
				if (sar[i] * 10 / width % 10 > 5)
					(sar[i] += sar[i] / width * scale + scale);
				else
					(sar[i] += sar[i] / width * scale);
			}
			i++;
		}
		list = list->next;
	}
}