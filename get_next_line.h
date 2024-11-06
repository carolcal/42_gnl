/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:32:26 by cayamash          #+#    #+#             */
/*   Updated: 2024/11/04 18:48:06 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>

char	*get_next_line(int fd);
size_t	line_len(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
unsigned char	*ft_strchr(const char *s, int c);

#endif
