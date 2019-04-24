/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:10:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/23 15:17:53 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(const int fd)
{
	char	*str;
	char	*tmp;
	int i;

	tmp = NULL;
	str = ft_strnew(1);
	while (get_next_line(fd, &tmp) == 1)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	return (str);
}

void	fillit(const int fd)
{
	char	*filedata;

	filedata = read_file(fd);
}
