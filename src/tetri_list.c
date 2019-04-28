//
// Created by Abbie Calandra on 2019-04-28.
//

#include "libft.h"

void	transform_tetri_array(char	sar[4])
{
	int		i;
	char	temp;

	i = 0;
	while (i < 3)
		sar[i] != 1 ? sar[i++]-- : i++;
	i = -1;
	while (++i < 2)
		if (sar[i] > 1 && sar[i] < 4)
		{
			temp = sar[0];
			if (i == 1 && (temp != 1 && sar[1] == 3))
			{
				sar[0] = sar[2];
				sar[1] = 0 - (sar[1] + sar[2]);
				sar[2] = 0 - temp;
			}
			else if (i == 0)
			{
				sar[0] = sar[1];
				sar[1] = sar[2];
				sar[2] = 0 - (sar[0] + sar[1] + temp);
			}
		}
}

void	add_tetri(t_list **tlist, const int mas[5], const char *data)
{
	t_list	*newlist;
	t_list	*list;
	int		i;
	int 	j;
	int		k;
	char	sar[4];

	if (mas[2] != 0 || !(newlist = ft_lstnew(NULL, 0)))
		return ;
	i = 0;
	k = mas[3];
	j = 0;
	while (i < 3)
	{
		k += j;
		j = 1;
		while (data[k + j] != '#')
			j++;
		sar[i++] = j;
	}
	transform_tetri_array(sar);
	sar[3] = 'A' + mas[4];
	newlist->content = sar;
	if ((list = *tlist))
		list->next = newlist;
	else
		*tlist = newlist;
}

/*
.#.. j = 4, mas[1] = 1, j > 1 && j < 5
##..	3, 1, 4
.#..	1, 4, -8
....

.#..	4, 3, 1
.#..	1, -4, -4
##..
....

.#..	3, 1, 1
###.	1, 1, -5
....
....

...#	2, 1, 1
.###	1, 1, -4
....
....

.##.	1, 2, 1
##..	1, -3, -1
....
....

.#..	3, 1, 3
##..	1, 3, -7
#...
 */

