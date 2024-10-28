/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:11:11 by svereten          #+#    #+#             */
/*   Updated: 2024/10/28 17:19:10 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERNAL_H
# define INTERNAL_H

typedef enum e_option
{
	GET,
	FREE,
}	t_option;

typedef enum e_gc_node_type
{
	FD,
	PTR
}	t_gc_node_type;

typedef union u_data
{
	int		fd;
	void	*ptr;
}	t_data;

typedef struct s_gc_node
{
	t_data				data;
	t_gc_node_type		type;
	struct s_gc_node	*next;
}	t_gc_node;

typedef struct s_gc_data
{
	t_gc_node	*head;
	t_gc_node	*tail;
}	t_gc_data;

t_gc_data	*gc(t_option op);
void		gc_add_data(t_gc_node_type t, t_data data);

#endif // !INTERNAL_H
