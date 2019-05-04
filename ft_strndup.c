/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:30:14 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/22 16:00:34 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char			*newstr;
	unsigned int	i;

	if (!(newstr = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	return (newstr);
}
