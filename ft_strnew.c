/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:41:34 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/18 18:29:34 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;
	size_t	buffer;

	buffer = size + 1;
	if (size == buffer - 1)
		if ((p = (char*)malloc(sizeof(char) * buffer)))
			return (ft_memset(p, '\0', buffer));
	return (NULL);
}
