/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:17:48 by svereten          #+#    #+#             */
/*   Updated: 2025/04/17 13:03:31 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/string.h"
#include "libft/stdlib.h"

static int	ft_isinset(char const *set, char c)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len && c != set[i])
		i++;
	if (!set[i])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && !ft_isinset(set, s1[i]))
		i++;
	start = i;
	end = i;
	while (s1[i])
	{
		if (ft_isinset(set, s1[i]))
			end = i;
		i++;
	}
	res = ft_substr(s1, start, end - start + 1);
	if (!res)
		return (ft_free(STR, &s1), NULL);
	return (ft_free(STR, &s1), res);
}
