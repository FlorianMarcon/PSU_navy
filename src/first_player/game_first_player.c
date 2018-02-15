/*
** EPITECH PROJECT, 2017
** game_first_player
** File description:
** game_first_player
*/

#include <stdlib.h>
#include <unistd.h>
#include "header_navy.h"
#include "my.h"
#include "get_next_line.h"
navy_t	*prepare_nav(char *path);
int	recuperate_info(void);
int	party_is_finished(navy_t *nav);
point_t	*translate_coordonate(char *msg);
int	send_message(int v);
void	display_all(navy_t *nav);
int	wait_message(navy_t *nav);
int	receive_message(navy_t *nav);
void	destroy_nav(navy_t *nav);

int	game_first_player(char *path)
{
	navy_t *nav = prepare_nav(path);
	int res = 0;

	if (nav == NULL)
		return (84);
	display_all(nav);
	while ((res = party_is_finished(nav)) == 0) {
		if (receive_message(nav) == -1) {
			destroy_nav(nav);
			return (0);
		}
		if (wait_message(nav) == 0) {
			destroy_nav(nav);
			return (0);
		}
		display_all(nav);
	}
	destroy_nav(nav);
	return (res);
}
