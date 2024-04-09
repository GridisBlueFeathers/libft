/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:16:39 by svereten          #+#    #+#             */
/*   Updated: 2024/04/09 13:43:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (!lst || !del)
		return ;
	if (!*lst)
		return ;
	cur = *lst;
	while (cur->next)
	{
		next = cur->next;
		del(cur->content);
		free(cur);
		cur = next;
	}
	del(cur->content);
	free(cur);
	*lst = 0;
}
