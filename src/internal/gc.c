/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:45 by svereten          #+#    #+#             */
/*   Updated: 2024/10/28 17:26:17 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "internal.h"
#include "libft/libft.h"

static t_gc_data	*gc_init(void)
{
	t_gc_data	*res;

	res = (t_gc_data *)ft_calloc_no_gc(1, sizeof(t_gc_data));
	return (res);
}

static void	gc_free(t_gc_data *gc)
{
	t_gc_node	*cur;
	t_gc_node	*tmp;

	cur = gc->head;
	while (cur)
	{
		tmp = cur->next;
		if (cur->type == FD)
			close(cur->data.fd);
		else
			free(cur->data.ptr);
		free(cur);
		cur = tmp;
	}
	free(gc);
}

void	gc_add_data(t_gc_node_type t, t_data data)
{
	t_gc_node	*node;

	node = (t_gc_node *)ft_calloc_no_gc(1, sizeof(t_gc_node));
	if (!node)
		ft_panic(1, NULL);
	node->type = t;
	node->data = data;
	if (gc(GET)->tail)
	{
		gc(GET)->tail->next = node;
		gc(GET)->tail = node;
		return ;
	}
	gc(GET)->head = node;
	gc(GET)->tail = node;
}

t_gc_data	*gc(t_option op)
{
	static t_gc_data	*gc;

	if (op == GET)
	{
		if (!gc)
			gc = gc_init();
		return (gc);
	}
	if (op == FREE)
	{
		gc_free(gc);
		gc = NULL;
		return (NULL);
	}
	return (NULL);
}
