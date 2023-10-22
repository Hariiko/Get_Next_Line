/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:51:13 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/22 17:36:39 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	if(!s1)
	{
		s1 = malloc(sizeof(char) +1);
		if(!s1)
		{
			free(s1);
			return (s1);
		}
		s1[0] = 0;
	}
	temp = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!temp)
		return (NULL);
	j = -1;
	i = -1;
	while (s1 && s1[++i])
		temp[i] = s1[i];
	while (s2[++j])
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	free(s1);
	return (temp);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while  (s[i] != '\0')
		i++;
	return (i);
}
