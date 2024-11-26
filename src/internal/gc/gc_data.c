/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:41:45 by svereten          #+#    #+#             */
/*   Updated: 2024/11/26 17:34:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gc.h"
#include "internal.h"
#include "libft/stdlib.h"

void	gc_data_add(t_gc_node_type t, t_data data)
{
	t_gc_node	*node;

	node = (t_gc_node *)ft_calloc_no_gc(1, sizeof(t_gc_node));
	if (!node)
		ft_panic(1, NULL);
	node->type = t;
	node->data = data;
	gc(GET)->amount++;
	if (gc(GET)->tail)
	{
		gc(GET)->tail->next = node;
		gc(GET)->tail = node;
		return ;
	}
	gc(GET)->head = node;
	gc(GET)->tail = node;
}

void	gc_data_remove(t_gc_node_type t, t_data data)
{
	t_gc_node	*cur;
	t_gc_node	*tmp;

	cur = gc(GET)->head;
	while (cur && cur->next
		&& ((t == PTR && cur->next->data.ptr != data.ptr)
			|| (t == FD && cur->next->data.fd != data.fd)))
		cur = cur->next;
	if (!cur->next)
		return ;
	gc(GET)->amount--;
	if (t == PTR)
		free(data.ptr);
	tmp = cur->next;
	cur->next = cur->next->next;
	free(tmp);
}
