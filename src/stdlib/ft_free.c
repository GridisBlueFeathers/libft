/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:33:07 by svereten          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/stdlib.h"
#include "gc.h"

/**
 * Frees a string array
 */
static void	ft_free_str_arr(char **arr)
{
	int		i;
	t_data	data;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		data.ptr = arr[i];
		gc_data_remove(PTR, data);
		i++;
	}
	data.ptr = arr;
	gc_data_remove(PTR, data);
}

void	ft_free(t_type type, void *ref)
{
	void	*ptr;
	t_data	data;

	ptr = *(void **)ref;
	data.ptr = ptr;
	if (type == STR || type == STRUCT)
		gc_data_remove(PTR, data);
	if (type == STR_ARR)
		ft_free_str_arr((char **)ptr);
	*(void **)ref = NULL;
}