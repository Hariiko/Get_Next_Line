/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:17 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/13 19:34:43 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char* read_file()
{
 

}*/


char *get_next_line(int fd)
{
	char *buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));

	buffer[BUFFER_SIZE] = '\0';
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

int main ()
{
	int file;
	char* readfile;
	file = open("test.txt", O_RDONLY);
	if (!file || file == -1)
		printf("ERROR");
	readfile = get_next_line(file);
	printf("%d", file);
	printf("%d\n", BUFFER_SIZE);
	printf("%s\n", readfile);
	close(file);
	return 0;
}
