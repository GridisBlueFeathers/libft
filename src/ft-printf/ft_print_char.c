/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:50:48 by svereten          #+#    #+#             */
/*   Updated: 2024/09/04 15:17:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/ft_printf.h"

int	ft_print_char(char c)
{
	int	bytes_written;

	bytes_written = write(STDOUT_FILENO, &c, 1);
	return (bytes_written);
}
