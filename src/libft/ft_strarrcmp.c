/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:19:25 by svereten          #+#    #+#             */
/*   Updated: 2024/08/27 15:26:27 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

int	ft_strarrcmp(char **arr1, char **arr2)
{
	int	i;

	if (!arr1 && !arr2)
		return (1);
	i = 0;
	while (arr1[i] && arr2[i])
	{
		if (ft_strcmp(arr1[i], arr2[i]))
			return (0);
		i++;
	}
	if ((arr1[i] && !arr2[i]) || (!arr1[i] && arr2[i]))
		return (0);
	return (1);
}
