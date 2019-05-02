/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:08:28 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/30 13:10:36 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 545

void	fillit(t_list **tlist);
void	ft_error(void);
void	check_data(char *data, t_list **tlist);
void	read_file(char *file, char *buf);
void	add_tetri(t_list **tlist, int *mas, const char *data);
void	scale_tetri(t_list **tlist, int width, int scale);
char	*create_map(t_list **tlist, int *width);
void	scale_map(char **map, int *width, int scale);
void	*del(void *content, size_t size);

#endif
