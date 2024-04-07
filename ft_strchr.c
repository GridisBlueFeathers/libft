/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:49 by svereten          #+#    #+#             */
/*   Updated: 2024/04/06 22:25:53 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (!s[i] && (unsigned char)c)
		return (res);
	res = &((char *)s)[i];
	return (res);
}
