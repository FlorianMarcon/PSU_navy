/*
** EPITECH PROJECT, 2017
** verify_connexion
** File description:
** verify_connexion
*/

#include "header_navy.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_printf.h"

void	verify_connexion(int sig, siginfo_t *inf, void *a)
{
	usleep(200000);
	if (sig == sig && a == a && inf->si_pid != pid_enemy)
		pid_enemy = -1;
	else {
		if (kill(pid_enemy, SIGUSR1) != 0)
			pid_enemy = -1;
}}

void	second_verify_connexion(int sig, siginfo_t *inf, void *a)
{
	if (sig == sig && a == a && inf->si_pid != pid_enemy)
		pid_enemy = -1;
}
