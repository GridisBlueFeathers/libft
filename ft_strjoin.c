/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:02:46 by svereten          #+#    #+#             */
/*   Updated: 2024/04/04 17:14:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_appendstr(char *res, char const *s)
{
	int	i;
	int	j;

	i = ft_strlen(res);
	j = 0;
	while (s[j])
	{
		res[i + j] = s[j];
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	ft_appendstr(res, s1);
	ft_appendstr(res, s2);
	return (res);
}
