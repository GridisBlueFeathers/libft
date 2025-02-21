/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:38:07 by svereten          #+#    #+#             */
/*   Updated: 2025/02/21 17:11:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ctype.h"
#include "libft/string.h"

static int	basic_check(char *str)
{
	int	i;

	if (ft_strlen(str) > 20)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * For way too big of numbers check is performed in basic check
 * For overflow check if strlen is less than 20, it won't overflow int64
 */
static int	overflow_check(char *str)
{
	if ((str[0] == '-' || str[0] == '+') && ft_strlen(str) < 20)
		return (1);
	if (ft_strlen(str) < 19)
		return (1);
	if (str[0] == '-' && ft_strcmp(&str[1], "9223372036854775808") <= 0)
		return (1);
	if (str[0] == '+' && ft_strcmp(&str[1], "9223372036854775807") <= 0)
		return (1);
	if (ft_isdigit(str[0]) && ft_strcmp(str, "9223372036854775807") <= 0)
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{

	if (!str || !basic_check(str) || !overflow_check(str))
		return (0);
	return (1);
}
