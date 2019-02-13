/*
** EPITECH PROJECT, 2017
** send_message
** File description:
** send_message
*/

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "header_navy.h"
#include "my.h"

int	send_message(int v)
{
	int i = 0;

	while (i != v) {
		if (kill(pid_enemy, SIGUSR1) != 0)
			return (-1);
		i++;
		usleep(2000);
	}
	if (kill(pid_enemy, SIGUSR2) != 0)
		return (-1);
	return (0);
}
