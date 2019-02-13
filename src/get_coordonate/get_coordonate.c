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

int	verify_size_coordonate(coord_t **cor)
{
	int i = 0;
	int result = 0;

	while (cor[i] != NULL) {
		result += cor[i++]->size;
	}
	if (result != SIZE)
		return (0);
	return (1);
}

coord_t	**get_coordonate(char *path)
{
	int fd = open(path, O_RDONLY);
	char *str = NULL;
	coord_t **cor;
	int i = 0;

	if (fd == -1 || (cor = create_list_coord()) == NULL)
		return (NULL);
	while ((str = get_next_line(fd)) != NULL) {
		if (i == 4 || (cor[i++] = put_data_in_coord(str)) == NULL) {
			destroy_list_coord(cor);
			close(fd);
			return (NULL);
		}
	}
	close(fd);
	if (i != 4 || verify_size_coordonate(cor) != 1) {
		destroy_list_coord(cor);
		return (NULL);
	}
	return (cor);
}
