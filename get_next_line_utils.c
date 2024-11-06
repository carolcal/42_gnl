/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:17:13 by cayamash          #+#    #+#             */
/*   Updated: 2024/11/06 18:34:22 by cayamash         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;

	dlen = 0;
	slen = ft_strlen(src);
	if (size > 0)
	{
		while (src[dlen] != '\0' && dlen < (size - 1))
		{
			dst[dlen] = src[dlen];
			dlen++;
		}
		dst[dlen] = '\0';
	}
	return (slen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while ((i < slen) && (dlen + i) < (size - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

ssize_t	ft_line_len(const char *s)
{
	ssize_t i;

	i = 0;
	while (s[i] != '\n' && i != BUFFER_SIZE)
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t		total_size;

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

	s_len = 0;
	while(s[s_len] != '\0')
		s_len++;
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
	ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		join_len;
	char	*s_join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_len = s1_len + s2_len + 1;
	s_join = ft_calloc(join_len, sizeof(char));
	if (!s_join)
		return (NULL);
	ft_strlcpy(s_join, s1, s1_len + 1);
	ft_strlcat(s_join, s2, join_len);
	//free(s1); //verificar se precisa
	//free(s2); //verificar se precisa
	return (s_join);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
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