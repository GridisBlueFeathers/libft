/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:20:19 by svereten          #+#    #+#             */
/*   Updated: 2024/08/14 17:29:08 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

/**
 * Counts strings in string array
 * 
 * Protected
 */
static size_t	count_strings(char **arr)
{
	size_t	res;

	if (!arr)
		return (0);
	res = 0;
	while (arr[res])
	{
		res++;
	}
	return (res);
}

/**
 * Duplicates string array
 *
 * Protected
 */
char	**ft_strarrdup(char **arr)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(count_strings(arr) + 1, sizeof(char *));
	if (!arr || !res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
		{
			ft_free(STR_ARR, res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
