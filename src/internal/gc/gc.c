/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:45 by svereten          #+#    #+#             */
/*   Updated: 2025/04/14 20:39:23 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "internal.h"
#include "gc.h"
#include "libft/libft.h"

static t_gc_data	*gc_init(void)
{
	t_gc_data	*res;

	res = (t_gc_data *)ft_calloc_no_gc(1, sizeof(t_gc_data));
	return (res);
}

static void	*gc_free(t_gc_data *gc)
{
	t_gc_node	*cur;
	t_gc_node	*tmp;

	if (!gc)
		return (NULL);
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
	return (NULL);
}

t_gc_data	*gc(t_option op)
{
	static t_gc_data	*gc;

	if (op == GET && !gc)
		gc = gc_init();
	if (op == FREE)
		gc = gc_free(gc);
	return (gc);
}

__attribute__((constructor(100)))
static	void	gc_constructor(void)
{
	if (!gc(GET))
		exit(1);
}

__attribute__((destructor(100)))
static	void	gc_destructor(void)
{
	gc(FREE);
}
