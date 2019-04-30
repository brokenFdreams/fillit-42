/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:46:40 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 12:50:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	read_file(char *file, char *buf)
{
	char	c[1];
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1 || ret > 545)
		ft_error();
	buf[ret] = '\0';
	ret = read(fd, c, 1);
	if (ret != 0)
		ft_error();
	close(fd);
}
