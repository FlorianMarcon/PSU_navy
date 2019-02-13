/*
** EPITECH PROJECT, 2017
** first_player
** File description:
** first_player
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "header_navy.h"
#include "my.h"
#include "my_printf.h"
map_t	*create_base_map(int x, int y);
navy_t	*prepare_nav(char *path);
void	display_map_me(map_t *map);
void	register_pid(int sig, siginfo_t *inf, void *a);
void	second_verify_connexion(int sig, siginfo_t *inf, void *a);
int	game_first_player(char *path);

int	connection_game(void)
{
	struct sigaction *act = malloc(sizeof(*act));

	if (act == NULL)
		return (-1);
	my_printf("my_pid: %i\n", getpid());
	my_printf("waiting for enemy connection...\n\n");
	sigemptyset(&act->sa_mask);
	act->sa_sigaction = &register_pid;
	act->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, act, NULL);
	pause();
	act->sa_sigaction = &second_verify_connexion;
	sigaction(SIGUSR1, act, NULL);
	pause();
	free(act);
	return (1);
}
int	first_player(char *path)
{
	int res;
	navy_t *nav = prepare_nav(path);

	if (nav == NULL || connection_game() == -1)
		return (84);
	if (pid_enemy == -1)
		return (84);
	my_printf("enemy connected\n\n");
	res = game_first_player(path);
	return (res);
}
