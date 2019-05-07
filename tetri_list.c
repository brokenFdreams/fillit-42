/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:30:10 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/07 16:30:47 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del(void *content, size_t size)
{
	(void)size;
	if (content)
		free(content);
}

void	ft_list_push_back(t_list **begin_list, char *sar)
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
	return (count);
}

void	add_tetri(t_list **tlist, int *mas, const char *data)
{
	int		i;
	int		j;
	int		count;
	char	sar[4];

	i = 0;
	j = 1;
	count = 0;
	while (i < 3)
	{
		while (data[mas[3] + j] != '#' && data[mas[3] + j])
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

void	scale_tetri(t_list **tlist, int scale)
{
	t_list	*list;
	char	old[3];
	int		l;
	char	*cnt;

	list = *tlist;
	while (list && (cnt = list->content))
	{
		l = 0;
		old[0] = cnt[0];
		old[1] = cnt[1];
		old[2] = cnt[2];
		if (old[0] != 1)
			l += scale;
		cnt[0] += l;
		if (old[1] - old[0] != 1)
			l += scale;
		cnt[1] += l;
		if (old[2] - old[1] != 1)
			l += scale;
		cnt[2] += l;
		list = list->next;
	}
}
