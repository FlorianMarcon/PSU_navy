/*
** EPITECH PROJECT, 2017
** header_navy
** File description:
** header_navy
*/

#ifndef NAVY_
#define NAVY_

#define SIZE 14
#define NB_ARGU 4
#define MAP_X 8
#define MAP_Y 8

int pid_enemy;

int	my_navy(int nb_argu, char **av);

int	first_player(char *path);

int	second_player(char **av);

typedef struct laos {
	int result;
	int finish;
}laos_t;

//
typedef struct point {
	int x;
	int y;

	int value;
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
