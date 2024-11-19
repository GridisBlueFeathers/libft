/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:33:07 by svereten          #+#    #+#             */
/*   Updated: 2024/11/19 17:09:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
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
	data.ptr = arr;
	while (arr[i])
	{
		ft_free(STR, &arr[i]);
		i++;
	}
	gc_data_remove(PTR, data);
}

/**
 * Frees variable and sets it to NULL, variable should be passed by reference
 */
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
