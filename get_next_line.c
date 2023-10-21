/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:17 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/20 20:30:54 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	
//Esta funcion tiene que cre:qar un  nuevo storage, que no contenga la linea extrada,
//y solo guarde e; troxo de informaciuon que queremos guardar
// storage -> "hola que tal\n bien\0"
// new_storage -> " bien\0"
/*char *update_storage(char *storage)
{
		char *new_storge

		//calcularia el tamano necesario
		//copiaria lo que quiero guardar

		free(storage);
		return(new_storage);
}*/

// Esto tiene que llenar el storage con sufieciente informacion como para que luego 
// podamos extraer una linea. LLnearemos storage hasta que haya un \n, o num_bytes = 0,
// que significaria que hemos llegado al final del archivo
char *read_file(int fd, char *storage)
{
	int i;
	char *buffer;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	i = 1;

	while(i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);	
		if (i == -1)
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
	char 		*line;

	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	if(!storage || (storage && !ft_strchr(storage, '\n')))
		storage = read_file(fd, storage);
	if (!storage)
		return (NULL);
	// Necesito extraer una linea de storage
	// line = extract_line(storage);
	// if(!line)
	//  return(NULL)
	// storage = update_storage(storage)
	return (line);
}

int main ()
{
	int file;
	char* readfile;
	file = open("test.txt", O_RDONLY);
	if (!file || file == -1)
		printf("ERROR");
	readfile = get_next_line(file);
	printf("%s\n", readfile);
	printf("%d\n", file);
	printf("%d\n", BUFFER_SIZE);
	close(file);
	return 0;
}
