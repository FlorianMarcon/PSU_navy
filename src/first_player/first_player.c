/*
** EPITECH PROJECT, 2017
** first_player
** File description:
** first_player
*/

#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "my_printf.h"
#include "header_navy.h"

int	first_player(char **av)
{/*
	struct sigaction ac;

	ac.sa_handler = &inutile_function;
	sigaction(SIGUSR1, &ac, NULL);
	my_printf("my_pid:	%i\n", getpid());
	my_printf("waiting for enemy %sconnexion...\n", av[0]);
	pause();
	my_printf("enemy conected\n");*/
	navy_t nav = {generate_map_me(av[0]), generate_map_you()};
	return (1);
}
