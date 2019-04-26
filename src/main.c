/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:34:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/26 13:29:45 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	char	*data;
	int		fd;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		exit(0);
	}
	data = read_file(argv[1]);
	check_data(data);
	fillit(data);
	return (0);
}
