/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrpop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:27:46 by svereten          #+#    #+#             */
/*   Updated: 2025/05/23 15:29:36 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/stdlib.h"
#include "libft/strarr.h"

char	**ft_strarrpop(char **arr, int idx)
{
	char	**res;
	int		len;
	int		i;
	int		offset;

	if (!arr)
		return (NULL);
	len = ft_strarrlen(arr);
	if (!len || idx < 0 || idx >= len)
		return (arr);
	res = (char **)ft_calloc(len, sizeof(char *));
	i = 0;
	offset = 0;
	while (arr[i])
	{
		if (i != idx)
			res[i - offset] = arr[i];
		else
			offset = 1;
		i++;
	}
	return (ft_free(STRUCT, &arr), res);
}
