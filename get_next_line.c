/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:17 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/30 16:16:09 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *buffer)
{
	char	*ptr;
	int		numptr;
	int		i;

	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
		return (ft_free(&buffer));
	numptr = ft_strlen(ptr);
	i = ft_strlen(buffer);
	ptr = ft_calloc(numptr + 1, 1);
	if (!ptr)
		return (ft_free(&buffer));
	ptr[numptr] = '\0';
	while (--numptr >= 0)
		ptr[numptr] = buffer[i--];
	ft_free(&buffer);
	return (ptr);
}

char	*trim(char	*storage)
{
	int		i;
	char	*t;

	if (!storage || !*storage)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	t = malloc(i + 1);
	if (!t)
		return (NULL);
	t[i] = '\0';
	while (--i >= 0)
		t[i] = storage[i];
	return (t);
}

char	*ft_add_buffer(char *buffer)
{
	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (ft_free(&buffer));
	}
	return (buffer);
}

char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	int		nread;

	nread = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (ft_free(&storage));
	}
	buffer[0] = '\0';
	while (nread > 0 && !ft_strchr(buffer, '\n'))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread < 0)
		{
			free (buffer);
			return (ft_free(&storage));
		}
		buffer[nread] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free (buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = trim(storage);
	if (!line)
		return (ft_free(&storage));
	storage = ft_clean(storage);
	return (line);
}

/*int main() {
    int file;
    char *readfile;

    file = open("test.txt", O_RDONLY);

    if (file == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
    while ((readfile = get_next_line(file)) != NULL) {
		printf("Línea leída:%s:\n", readfile);
        free(readfile);
   }
    close(file);

    return 0;
}*/
