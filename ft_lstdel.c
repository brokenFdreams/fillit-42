/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:10:42 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/14 15:03:18 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;

	if (alst && del)
	{
		if (*alst)
		{
			list = *alst;
			list = list->next;
			ft_lstdel(&list, del);
			ft_lstdelone(alst, del);
			*alst = NULL;
		}
	}
}
