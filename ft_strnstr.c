/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:05 by svereten          #+#    #+#             */
/*   Updated: 2024/04/03 18:54:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	char	*res;

	i = 0;
	res = 0;
	little_len = ft_strlen(little);
	if (!big && !len)
		return (0);
	if ((len == little_len && !ft_strncmp(big, little, len))
		|| (!little[i]))
		return ((char *)big);
	while (i < len - little_len && big[i])
	{
		if (!ft_strncmp(&big[i], little, little_len))
		{
			res = &((char *)big)[i];
			break ;
		}
		i++;
	}
	return (res);
}
