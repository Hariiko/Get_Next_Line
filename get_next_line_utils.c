/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:51:13 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/29 18:48:03 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	if (!s1)
	{
		s1 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	temp = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!temp)
		return (ft_free(&s1));
	j = 0;
	i = 0;
	while (s1[i])
		temp[j++] = s1[i++];
	i = 0;
	while (s2[i])
		temp[j++] = s2[i++];
	temp[j] = '\0';
	free(s1);
	return (temp);
}

void	*ft_calloc(int quantity, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(quantity * size);
	if (!str)
		return (NULL);
	while (i < quantity * size)
		str[i++] = 0;
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
