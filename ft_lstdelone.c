/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:27:28 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/14 15:03:38 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;

	if (alst && del)
	{
		if (*alst)
		{
			list = *alst;
			del(list->content, list->content_size);
			free(*alst);
			*alst = NULL;
		}
	}
}
