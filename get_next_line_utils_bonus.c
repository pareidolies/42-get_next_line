/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:47:32 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/21 13:46:40 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (c == 0)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if ((char)c == str[i])
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	len_s = ft_strlen(s);
	if (len_s < start)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	i = -1;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
