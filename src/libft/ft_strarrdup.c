/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:20:19 by svereten          #+#    #+#             */
/*   Updated: 2024/08/18 15:06:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

/**
 * Duplicates string array
 *
 * Protected
 */
char	**ft_strarrdup(char **arr)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(ft_strarrlen(arr) + 1, sizeof(char *));
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
