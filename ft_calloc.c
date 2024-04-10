/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:56:08 by svereten          #+#    #+#             */
/*   Updated: 2024/04/10 19:35:14 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	size_t			i;
	unsigned int	ui_max;
	size_t			ul_max;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ui_max = 0xffffffff;
	ul_max = 0xffffffffffffffff;
	if (nmemb > (ul_max / size))
		return (0);
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

int main()
{
	printf("%p\n", ft_calloc(UINT_MAX, 1));
}
