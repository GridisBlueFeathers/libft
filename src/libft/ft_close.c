/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:58:40 by svereten          #+#    #+#             */
/*   Updated: 2024/11/20 17:01:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gc.h"
#include "libft/libft.h"
#include <unistd.h>

void	ft_close(int fd)
{
	t_data data;

	if (fd < 0)
		return ;
	if (close(fd) == -1)
		ft_panic(1, NULL);
	data.fd = fd;
	gc_data_remove(FD, data);
}
