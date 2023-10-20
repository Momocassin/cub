/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:07:52 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/18 19:04:32 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!cpy)
		return (NULL);
	while (s[++i])
		cpy[i] = s[i];
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(const char *s, unsigned int start, size_t len, bool ret)
{
	char		*new;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (ret == 0)
		while (i < len && s[start] && start < ft_strlen(s))
			new[i++] = s[start++];
	else
	{
		while (i < len && s[start] && start < ft_strlen(s))
		{
			if (s[start] == ' ' || s[start] == '\t')
				start++;
			else
				new[i++] = s[start++];
		}
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_cpy;

	i = 0;
	s_cpy = (char *)s;
	if (!s)
		return (NULL);
	while (s_cpy[i])
	{
		if (s_cpy[i] == c)
		{
			return (s_cpy + i);
		}
		i++;
	}
	if (c == '\0')
	{
		return (s_cpy + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	s3 = (char *)calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[j])
		s3[i++] = s1[j++];
	free(s1);
	s1 = NULL;
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
