/*
** EPITECH PROJECT, 2017
** get_coordonate
** File description:
** get_coordonate
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"
#include "header_navy.h"
coord_t	*put_data_in_coord(char *str);
void	destroy_coord(coord_t *cor);

coord_t	**create_list_coord(void)
{
	coord_t **cor = malloc(sizeof(*cor) * 5);

	if (cor == NULL)
		return (cor);
	for (int i = 0; i != 5; i++)
		cor[i] = NULL;
	return (cor);
}

void	destroy_list_coord(coord_t **cor)
{
	int i = 0;

	while (i != 4) {
		if (cor[i] != NULL)
			destroy_coord(cor[i]);
		i++;
	}
	free(cor);
}

coord_t	**get_coordonate(char *path)
{
	int fd = open(path, O_RDONLY);
	char *str = NULL;
	coord_t **cor;
	int i = 0;

	if (fd == -1)
		return (NULL);
	if ((cor = create_list_coord()) == NULL) {
		close(fd);
		return (NULL);
	}
	while ((str = get_next_line(fd)) != NULL) {
		if (i == 4) {
			destroy_list_coord(cor);
			close(fd);
			return (NULL);
		}
		cor[i] = put_data_in_coord(str);
		if (cor[i++] == NULL) {
			destroy_list_coord(cor);
			close(fd);
			return (NULL);
		}
	}
	close(fd);
	if (i != 4) {
		destroy_list_coord(cor);
		return (NULL);
	}
	return (cor);
}
