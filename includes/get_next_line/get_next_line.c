/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:25:42 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/24 22:30:55 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_check_next_line(char *leftover)
{
	char	*res;
	int		start;
	int		i;

	if (!leftover)
		return (NULL);
	i = -1;
	start = ft_strchr_gnl(leftover, '\n');
	if (start == -1)
		return (ft_strdup_gnl(leftover));
	res = malloc((start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (++i != start)
		res[i] = leftover[i];
	res[i] = '\n';
	res[i + 1] = 0;
	return (res);
}

static char	*ft_remove_last_line(char *leftover)
{
	int	start;

	start = ft_strchr_gnl(leftover, '\n');
	if (!leftover || start == -1 || ft_strlen_gnl(leftover) - start == 1)
		return (free(leftover), NULL);
	return (free(leftover), ft_strdup_gnl(leftover + start + 1));
}

char	*get_next_line(int fd)
{
	int			res_len;
	char		*tmp_buff;
	char		*s;
	static char	*leftover;

	tmp_buff = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (ft_strchr_gnl(leftover, '\n') == -1)
	{
		res_len = read(fd, s, BUFFER_SIZE);
		if (res_len <= 0)
			break ;
		s[res_len] = 0;
		leftover = ft_strjoin_gnl(leftover, s, res_len);
	}
	tmp_buff = ft_check_next_line(leftover);
	leftover = ft_remove_last_line(leftover);
	return (free(s), tmp_buff);
}
