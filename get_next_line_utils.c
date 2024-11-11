/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:17:13 by cayamash          #+#    #+#             */
/*   Updated: 2024/11/11 17:46:52 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && (total_size) / nmemb != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (total_size--)
		ptr[total_size] = 0;
	return ((void *)ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	s_len;
	unsigned int	size;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		start = 0;
		size = 0;
	}
	else if (len <= ((s_len + 1) - start))
		size = len;
	else
		size = (s_len - start);
	sub = ft_calloc((size + 1), sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	int		join_len;
	char	*s_join;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_len = s1_len + s2_len + 1;
	s_join = ft_calloc(join_len, sizeof(char));
	if (!s_join)
		return (NULL);
	i = 0;
	while (*s1)
		s_join[i++] = *s1++;
	while (*s2)
		s_join[i++] = *s2++;
	s_join[i] = '\0';
	return (s_join);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (*ptr != '\0' && *ptr != (unsigned char)c)
		ptr++;
	if (*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (NULL);
}
