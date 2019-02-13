/*
** EPITECH PROJECT, 2017
** put_data_in_coord
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "header_navy.h"
coord_t	*put_data_in_coord(char *str);
int	verify_coord(coord_t *cor);
point_t	*put_coordonate_in_point(char col, char line);
void	destroy_coord(coord_t *cor);
int	verify_size_coordonate(coord_t **cor);
coord_t	**get_coordonate(char *path);
void	destroy_list_coord(coord_t **cor);

Test(put_data_in_coord, test1)
{
	coord_t *cor = put_data_in_coord("SDFGHJKHGFD");

	cr_assert_eq(cor, NULL);
	cor = put_data_in_coord("1:B2:C3");
	cr_assert_eq(cor, NULL);
	cor = put_data_in_coord("8:B2:C3");
	cr_assert_eq(cor, NULL);
	cor = put_data_in_coord("2:B2:R3");
	cr_assert_eq(cor, NULL);
	cor = put_data_in_coord("8:R2:C3");
	cr_assert_eq(cor, NULL);
	cor = put_data_in_coord("2:B2:B4");
	cr_assert_eq(cor, NULL);
}
Test(put_data_in_coord, test2)
{
	coord_t *cor = put_data_in_coord("2:B2:B3");

	cr_assert_neq(cor, NULL);
	cr_assert_eq(cor->pa->x, 1);
	cr_assert_eq(cor->pa->y, 1);
	cr_assert_eq(cor->pb->x, 1);
	cr_assert_eq(cor->pb->y, 2);
	cr_assert_eq(cor->size, 2);
	destroy_coord(cor);
}

Test(verify_coord, test1)
{
	char str[] = "2:B2:B3";
	coord_t *cor = malloc(sizeof(*cor));

	if (cor != NULL) {
		cor->pa = put_coordonate_in_point(str[2], str[3]);
		cor->pb = put_coordonate_in_point(str[5], str[6]);
		cor->size = 2;
		cr_assert_eq(verify_coord(cor), 1);
		cor->size = 3;
		cr_assert_eq(verify_coord(cor), 0);
	}
}
Test(verify_size_coordonate, test1)
{
	coord_t **cor = get_coordonate("data/real_coordonate");

	cr_assert_eq(verify_size_coordonate(cor), 1);
	cor[0]->size = 16;
	cr_assert_eq(verify_size_coordonate(cor), 0);
	destroy_list_coord(cor);
}
