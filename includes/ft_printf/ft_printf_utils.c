/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:25:42 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/30 16:24:17 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen2(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			return ((char *) s + i);
	if (!c)
		return ((char *) s + i);
	return (0);
}
