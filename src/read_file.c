/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:46:40 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/24 15:31:59 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*read_file(char	*file)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	close(fd);
	if (ret == -1 || ret > 545)
		ft_error();
	buf[ret] = '\0';
	return (ft_strdup(buf));
}
