/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:51:13 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/22 20:16:37 by laltarri         ###   ########.fr       */
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
		s1 = malloc(sizeof(char));
		if(!s1)
		{
//			free(s1);
			return (NULL);
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
	//free(s1);
	return (temp);
}

void	*ft_calloc(int quantity, int size)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(quantity * size);
	if (!str)
		return (NULL);
	while (++i < quantity * size)
		str[i] = 0;
	return (str);
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
