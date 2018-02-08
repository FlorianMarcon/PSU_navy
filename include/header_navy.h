/*
** EPITECH PROJECT, 2017
** header_navy
** File description:
** header_navy
*/

#ifndef NAVY_
#define NAVY_

int	my_navy(int nb_argu, char **av);

int	first_player(char **av);

int	second_player(char **av);

//

typedef struct point {
	int x;
	int y;
}point_t;

typedef struct coord {
	point_t *pa;
	point_t *pb;
	int size;
}coord_t;

typedef struct map {
	int **map;
	int x;
	int y;
}map_t;

typedef struct navy {
	map_t *map_me;
	map_t *map_you;
}navy_t;

// utilitaries

int	how_x_map(char *str);
int	how_y_map(char *str);
void	inutile_function(int var);

#endif
