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

int	second_player(char **av)
{
	int id_f = my_getnbr(av[0]);
	struct sigaction ac;

	ac.sa_handler = &inutile_function;
	sigaction(SIGUSR1, &ac, NULL);
	my_printf("my_pid:	%i\n", getpid());
	if (kill(id_f, SIGUSR1) != 0)
		my_printf("%s\n", "echec");;
	pause();
	my_printf("successfully connected\n");
	return (1);
}
