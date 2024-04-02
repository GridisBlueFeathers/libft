/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:49:25 by svereten          #+#    #+#             */
/*   Updated: 2024/04/02 18:45:54 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*#include <stdio.h>
int main() {
	printf("Char is %c, Expected 0, Actual %d\n", -1, ft_isalnum(-1));
	printf("Char is %c, Expected 0, Actual %d\n", 47, ft_isalnum(47));
	printf("Char is %c, Expected 1, Actual %d\n", 48, ft_isalnum(48));
	printf("Char is %c, Expected 1, Actual %d\n", 57, ft_isalnum(57));
	printf("Char is %c, Expected 0, Actual %d\n", 58, ft_isalnum(58));
	printf("Char is %c, Expected 0, Actual %d\n", 64, ft_isalnum(64));
	printf("Char is %c, Expected 1, Actual %d\n", 65, ft_isalnum(65));
	printf("Char is %c, Expected 1, Actual %d\n", 90, ft_isalnum(90));
	printf("Char is %c, Expected 0, Actual %d\n", 91, ft_isalnum(91));
	printf("Char is %c, Expected 0, Actual %d\n", 96, ft_isalnum(96));
	printf("Char is %c, Expected 1, Actual %d\n", 97, ft_isalnum(97));
	printf("Char is %c, Expected 1, Actual %d\n", 122, ft_isalnum(122));
	printf("Char is %c, Expected 0, Actual %d\n", 123, ft_isalnum(123));
}*/
