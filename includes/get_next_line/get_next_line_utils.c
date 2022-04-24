/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:26:04 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/24 22:31:10 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
		*((char *)(dst + i)) = *((char *)(src + i));
	return (dst);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*target;
	size_t	i;
	size_t	target_len;

	i = -1;
	target_len = ft_strlen_gnl(s1) + 1;
	target = (char *) malloc(target_len * sizeof(char));
	if (!target)
		return (0);
	ft_memcpy_gnl(target, s1, target_len);
	return (target);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int		i;

	i = -1;
	if (!c || !s)
		return (i);
	while (s[++i])
		if (s[i] == (char) c)
			return (i);
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int len)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s2)
		return (s1);
	s1_len = ft_strlen_gnl(s1);
	s2_len = len;
	i = -1;
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = ft_memcpy_gnl(result, s1, s1_len);
	while (++i < s2_len)
		result[i + s1_len] = s2[i];
	result[s1_len + s2_len] = '\0';
	free(s1);
	return (result);
}
