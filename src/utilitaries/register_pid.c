/*
** EPITECH PROJECT, 2017
** register_pid
** File description:
** register_pid
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "header_navy.h"
#include "my.h"
#include "my_printf.h"

void	register_pid(int sig, siginfo_t *inf, void *a)
{
	usleep(20000);
	(void)sig;
	(void)a;
	pid_enemy = inf->si_pid;
	if (kill(pid_enemy, SIGUSR1) != 0)
		pid_enemy = -1;
}
