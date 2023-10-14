/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:17 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/14 16:36:49 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_file(int fd, char *buffer)
{
	int i;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	i = 1;
	while(i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);	
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		ft_putendl_fd(buffer,i);
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;	
	
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	return (buffer);
}

/*int main ()
{
	int file;
	char* readfile;
	file = open("test.txt", O_RDONLY);
	if (!file || file == -1)
		printf("ERROR");
	readfile = get_next_line(file);
	printf("%d\n", file);
	printf("%d\n", BUFFER_SIZE);
	close(file);
	return 0;
}*/
