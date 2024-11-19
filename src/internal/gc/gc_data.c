/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:41:45 by svereten          #+#    #+#             */
/*   Updated: 2024/11/19 16:45:59 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gc.h"
#include "internal.h"

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

