/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:32:09 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/11 02:00:52 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;
	size_t			x;

	x = 0;
	copy = (unsigned char *)b;
	while (x < len)
	{
		copy[x] = (unsigned char)c;
		x++;
	}
	return (b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[x] == ((unsigned char *)s2)[x]
			&& ((unsigned char *)s1)[x]
			&& ((unsigned char *)s2)[x] && x < (n - 1))
		x++;
	return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	tab = malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}
