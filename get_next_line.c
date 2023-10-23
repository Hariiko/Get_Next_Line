/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:17 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/23 17:49:45 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free(char **storage)
{
	if(*storage)
	{
		free(*storage);
		*storage = NULL;
	}
	return (NULL);
}
char *clean_storage(char *storage)
{
	char *ptr;
	
	if(!storage)
		return NULL;
	ptr = ft_calloc(BUFFER_SIZE + 1, 1);
	if(!ptr)
		return (NULL);
	ptr = ft_strchr(storage, '\n');
	ft_free(&storage);
	
	if(ptr && *ptr == '\n')
		return (++ptr);
	return (NULL);
}

char *addBuffer(char *buffer)
{
	if(!buffer)
	{
		buffer =(char *)malloc(1 * sizeof(char));
		if(!buffer)
				return (ft_free(&buffer));
		buffer[0] = '\0';
	}

	return (buffer);
}
char *extract_line(char *stogare)
{
	char	*line;
	int		i;
	char	*t;

	t = ft_strchr(stogare, '\n');
	if (!t)
		return (stogare);
	i = 1 + ft_strlen(stogare) - ft_strlen(t);
	line = malloc(i + 1 * sizeof(char)); 
	if (!line)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	while(i-- > 0)
		line[i] = stogare[i];
	//if (stogare)
	free(stogare);
	return (line);	
}

char *read_file(int fd, char *storage)
{
	int i;
	char *buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	
	//buffer[0] = '\0';
	i = 1;

	while(i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);	
		if (i < 1)
		{
			free(buffer);
			return (NULL);
		}
		
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}

char *get_next_line(int fd)
{
	static char *storage = NULL;	
	char 		*line = NULL;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
		return(NULL);
	storage = clean_storage(storage);
	return (line);
}

/*int main ()
{
	int file;
	char *readfile;
	file = open("test.txt", O_RDONLY);
	if (!file || file == -1)
		printf("ERROR");
	readfile = get_next_line(file);
	printf("%s", readfile);
	readfile = get_next_line(file);
	printf("%s", readfile);
	printf("%d\n", file);
	printf("%d\n", BUFFER_SIZE);
	close(file);
	return 0;
}*/
