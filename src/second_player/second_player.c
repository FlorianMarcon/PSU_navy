/*
** EPITECH PROJECT, 2017
** second_player
** File description:
** second_player
*/


#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "header_navy.h"
#include "my_printf.h"
void	verify_connexion(int sig, siginfo_t *inf, void *a);
int	game_second_player(navy_t *nav);
navy_t	*prepare_nav(char *path);

int	second_player(char **av)
{
	struct sigaction ac;
	int res = 84;
	navy_t *nav = prepare_nav(av[1]);

	if (nav == NULL)
		return (res);
	pid_enemy = my_getnbr(av[0]);
	sigemptyset(&ac.sa_mask);
	ac.sa_sigaction = &verify_connexion;
	ac.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ac, NULL);
	my_printf("my_pid: %i\n", getpid());
	if (kill(pid_enemy, SIGUSR1) != 0)
		return (-1);
	pause();
	if (pid_enemy == -1)
		return (-1);
	my_printf("successfully connected\n\n");
	res = game_second_player(nav);
	return (res);
}
