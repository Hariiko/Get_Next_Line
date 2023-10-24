/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:51:13 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/23 18:33:52 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char *ft_free(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
	//return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	//if(!s1 && !s2)
	//	return (NULL);
	/*else*/ if(!s1)
	{
		s1 = addBufTYfer(s1);
	}
	temp = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!temp)
		return (NULL);
		//return (ft_free(&temp));
	j = 0;
	i = 0;
	while (s1[i])
		temp[j++] = s1[i++];
	i = 0;
	while (s2[j])
		temp[j++] = s2[i++];
	temp[j] = '\0';
	//ft_free(&s1);
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
//	if (!s)
//		return (0);
	while  (s[i] != '\0')
		i++;
	return (i);
}
