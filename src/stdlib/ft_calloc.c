/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:56:08 by svereten          #+#    #+#             */
/*   Updated: 2024/11/22 17:09:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "internal.h"
#include "gc.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	t_data	data;

	data.ptr = ft_calloc_no_gc(nmemb, size);
	if (!data.ptr)
		ft_panic(1, NULL);
	gc_data_add(PTR, data);
	return (data.ptr);
}
