/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:56:08 by svereten          #+#    #+#             */
/*   Updated: 2024/10/28 17:16:49 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "internal.h"

void	*ft_calloc_no_gc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;
	size_t	res_size;

	res_size = nmemb * size;
	if (!nmemb || !size || res_size / size != nmemb)
		return (NULL);
	res = malloc(res_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

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
	gc_add_data(PTR, data);
	return (data.ptr);
}
