/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:08:28 by fsinged           #+#    #+#             */
/*   Updated: 2019/04/29 12:32:20 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"

# define BUFF_SIZE 545

void	fillit(t_list **tlist);
void	ft_error(void);
void	check_data(char *data, t_list **tlist);
void	read_file(char *file, char *buf);
void	add_tetri(t_list **tlist, int *mas, const char *data);
void	scale_tetri(t_list **tlist, int scale);

#endif
