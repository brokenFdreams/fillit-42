/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:34:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 17:13:16 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <time.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	data[BUFF_SIZE + 1];
	t_list	*tlist;

	tlist = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		exit(0);
	}
	read_file(argv[1], data);
	if (!data[0])
		ft_error();
	check_data(data, &tlist);
/*				start time			*/
	clock_t strt = clock();
/*									*/
	fillit(&tlist);
/*				show diff			*/
	clock_t endt = clock();
	double diff = ((double)endt - (double)strt) / CLOCKS_PER_SEC;
	printf("fillit run: %f sec\n", diff);
/*				end clock			*/
	ft_lstdel(&tlist, del);
	return (0);
}
