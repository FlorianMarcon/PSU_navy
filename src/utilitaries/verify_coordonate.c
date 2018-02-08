/*
** EPITECH PROJECT, 2017
** verify_coordonate
** File description:
** verify_coordonate
*/

#include "my.h"
#include "header_navy.h"

int	verify_coordonate(int x, int y)
{
	if (x < 0 || y < 0 || x > 7 || y > 7)
		return (0);
	else
		return (1);
}
