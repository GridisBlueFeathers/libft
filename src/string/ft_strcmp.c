/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:03:15 by svereten          #+#    #+#             */
/*   Updated: 2025/02/11 13:30:42 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/string.h"

int	ft_strcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1) + 1));
}
