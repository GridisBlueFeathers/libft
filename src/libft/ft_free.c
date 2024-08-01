/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:33:07 by svereten          #+#    #+#             */
/*   Updated: 2024/08/01 14:31:27 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

static void	ft_free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	ft_free(t_type type, void *ptr)
{
	if (type == PTR)
		free(ptr);
	if (type == STR_ARR)
		ft_free_str_arr(ptr);
	*(void **)ptr = NULL;
}
