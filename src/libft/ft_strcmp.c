/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:03:15 by svereten          #+#    #+#             */
/*   Updated: 2024/07/30 17:04:35 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}
