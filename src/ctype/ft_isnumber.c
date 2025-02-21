/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:38:07 by svereten          #+#    #+#             */
/*   Updated: 2025/02/21 18:34:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ctype.h"
#include "libft/string.h"

static int	find_beginning(char *str)
{
	int	res;

	res = 0;
	while (str[res] && ft_isspace(str[res]))
		res++;
	if (str[0] == '-' || str[0] == '+')
		res++;
	while (str[res] && str[res] == '0')
		res++;
	return (res);
}

static int	basic_check(char *str)
{
	int	i;
	int	has_digits;

	i = 0;
	has_digits = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		has_digits = 1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (has_digits);
}

static int	number_len(char *str)
{
	int	res;

	res = 0;
	while (str[res] && ft_isdigit(str[res]))
		res++;
	return (res);
}

/**
 * For way too big of numbers check is performed in basic check
 * For overflow check if strlen is less than 20, it won't overflow int64
 */
static int	overflow_check(char *str)
{
	int	i;

	i = find_beginning(str);
	if (number_len(&str[i]) < 19)
		return (1);
	if (number_len(&str[i]) > 19)
		return (0);
	if (str[0] == '-' && ft_strcmp(&str[i], "9223372036854775808") <= 0)
		return (1);
	if (str[0] == '+' && ft_strcmp(&str[i], "9223372036854775807") <= 0)
		return (1);
	if (ft_isdigit(str[0]) && ft_strcmp(&str[i], "9223372036854775807") <= 0)
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	if (!str || !basic_check(str) || !overflow_check(str))
		return (0);
	return (1);
}
