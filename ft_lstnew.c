/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:48:53 by svereten          #+#    #+#             */
/*   Updated: 2024/04/05 13:58:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!res)
		return (0);
	if (!content)
	{
		res->content = 0;
		return (res);
	}
	res->content = (void *)ft_calloc(ft_strlen((char *)content), sizeof(char));
	if (!res->content)
	{
		free(res);
		return (0);
	}
	ft_memcpy(res->content, content, ft_strlen((char *)content));
	return (res);
}
