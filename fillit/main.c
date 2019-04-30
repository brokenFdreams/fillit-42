/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:34:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 12:50:06 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	data[BUFF_SIZE + 1];
	t_list	*tlist = NULL;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		exit(0);
	}
	read_file(argv[1], data);
	check_data(data, &tlist);
	fillit(&tlist);
	return (0);
}