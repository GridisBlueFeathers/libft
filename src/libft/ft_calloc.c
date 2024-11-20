/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:56:08 by svereten          #+#    #+#             */
/*   Updated: 2024/11/20 17:12:57 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "internal.h"
#include "gc.h"

/**
 * Mimics `calloc`
 *
 * protected against and overflows 0 in arguments
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	t_data	data;

	data.ptr = ft_calloc_no_gc(nmemb, size);
	if (!data.ptr)
		ft_panic(1, NULL);
	gc_data_add(PTR, data);
	return (data.ptr);
}
