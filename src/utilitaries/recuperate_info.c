/*
** EPITECH PROJECT, 2017
** wait_x
** File description:
** wait_x
*/

#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include "header_navy.h"
#include "my.h"

laos_t	*get_laos(void)
{
	static laos_t t;
	static bool is_init = false;

	if (!is_init) {
		t.result = 0;
		t.finish = 0;
		is_init = true;
	}
	return (&t);
}

void	is_finished(int sig, siginfo_t *inf, void *a)
{
	(void)sig;
	(void)a;
	if (inf->si_pid == pid_enemy)
		get_laos()->finish = 1;
}

void	more_more(int sig, siginfo_t *inf, void *a)
{
	(void)sig;
	(void)a;
	if (inf->si_pid == pid_enemy)
		(get_laos()->result)++;
}
int	recuperate_info(void)
{
	struct sigaction act_usr_one;
	struct sigaction act_usr_two;

	get_laos()->finish = 0;
	get_laos()->result = 0;
	sigemptyset(&act_usr_one.sa_mask);
	sigemptyset(&act_usr_two.sa_mask);
	act_usr_one.sa_flags = SA_SIGINFO;
	act_usr_two.sa_flags = SA_SIGINFO;
	act_usr_two.sa_sigaction = &is_finished;
	act_usr_one.sa_sigaction = &more_more;
	sigaction(SIGUSR1, &act_usr_one, NULL);
	sigaction(SIGUSR2, &act_usr_two, NULL);
	while (get_laos()->finish != 1)
		pause();
	return (get_laos()->result);
}
