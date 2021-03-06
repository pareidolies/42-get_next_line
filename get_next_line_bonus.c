/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:51:22 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/21 13:44:46 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read(int fd, char *buf, char **str)
{
	int		r;
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		while (r > 0)
		{
			buf[r] = '\0';
			if (!*str)
				*str = ft_substr(buf, 0, r);
			else
			{
				tmp = ft_strjoin(*str, buf);
				free(*str);
				*str = tmp;
			}
			if (ft_strchr(buf, '\n'))
				break ;
			r = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

char	*ft_returnline(char **str)
{
	int		end;
	int		n;
	char	*ret;
	char	*tmp;

	if (!ft_strchr(*str, '\n'))
	{
		ret = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
		return (ret);
	}
	end = ft_strlen(*str);
	n = ft_strlen(ft_strchr(*str, '\n'));
	ret = ft_substr(*str, 0, end - n + 1);
	tmp = ft_substr(ft_strchr(*str, '\n'), 1, n - 1);
	free(*str);
	*str = tmp;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str[1024];

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	ft_read(fd, buf, &str[fd]);
	if (str[fd] == NULL || str[fd][0] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	return (ft_returnline(&str[fd]));
}
