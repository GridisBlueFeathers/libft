/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:55:29 by svereten          #+#    #+#             */
/*   Updated: 2024/11/22 17:30:14 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/stdlib.h"
#include "libft/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	i = 0;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
