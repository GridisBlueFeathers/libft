/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:50:29 by svereten          #+#    #+#             */
/*   Updated: 2024/04/05 14:47:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_int_len(int n)
{
	int	dec;
	int	n_cpy;

	n_cpy = n;
	dec = 1;
	if (n < 0)
		dec++;
	while (n_cpy / 10)
	{
		dec++;
		n_cpy /= 10;
	}
	return (dec);
}

static char	*ft_append_char(char *res, char c)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	res[i] = c;
	return (res);
}

static void	ft_itoa_worker(char *res, int n, int mod)
{
	if ((mod < 0 && n > -10) || (mod > 0 && n < 10))
	{
		ft_append_char(res, (n * mod) + '0');
		return ;
	}
	ft_itoa_worker(res, n / 10, mod);
	ft_itoa_worker(res, n % 10, mod);
}

char	*ft_itoa(int n)
{
	int		len;
	int		mod;
	char	*res;

	len = ft_get_int_len(n);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	mod = 1;
	if (n < 0)
	{
		ft_append_char(res, '-');
		mod = -1;
	}
	ft_itoa_worker(res, n, mod);
	return (res);
}
