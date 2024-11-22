/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:40:28 by svereten          #+#    #+#             */
/*   Updated: 2024/11/22 17:48:02 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STDIO_H
# define STDIO_H

# include <unistd.h>

/* libc copies */

//

/* libft */

//
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putstrarr_fd(char **arr, int fd);

#endif
