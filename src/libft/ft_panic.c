/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:59:05 by svereten          #+#    #+#             */
/*   Updated: 2024/10/28 17:12:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "internal.h"
#include "libft/ft_printf.h"
#include <errno.h>

void	ft_panic(int status, char *msg)
{
	if (msg)
		ft_dprintf(STDERR_FILENO, msg);
	else if (errno)
		perror("libft");
	ft_exit(status);
}
