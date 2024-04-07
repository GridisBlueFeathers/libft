/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:22:54 by svereten          #+#    #+#             */
/*   Updated: 2024/04/07 22:29:09 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(char c)
{
	char	*arr;
	int		i;

	arr = "\t\v\f\r\n ";
	i = 0;
	while (i < 6)
	{
		if (c == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	mod;
	int	res;

	i = 0;
	mod = 1;
	res = 0;
	while (ft_isspace(nptr[i]) || (nptr[i] == '+' && ft_isdigit(nptr[i + 1])))
		i++;
	while (nptr[i])
	{
		if (nptr[i] == '-' && ft_isdigit(nptr[i + 1]))
			mod = -1;
		else if (ft_isdigit(nptr[i]))
			res = res * 10 + mod * (nptr[i] - '0');
		else
			break ;
		i++;
	}
	return (res);
}
