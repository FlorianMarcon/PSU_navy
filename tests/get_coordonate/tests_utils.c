/*
** EPITECH PROJECT, 2017
** get_coordonate
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my_printf.h"
coord_t	**create_list_coord(void);
coord_t	**get_coordonate(char *path);
void	destroy_list_coord(coord_t **cor);

Test(create_list_coord, test1)
{
	coord_t **cor = create_list_coord();
	int i = 0;

	if (cor != NULL) {
		while (i != 5)
			cr_assert_eq(cor[i++], NULL);
	}
}

Test(get_coordonate, test1)
{
	coord_t **cor = get_coordonate("edguhyfcdoiuhj");

	cr_assert_eq(cor, NULL);
	cor = get_coordonate("data/false_coordonate");
	cr_assert_eq(cor, NULL);
	cor = get_coordonate("data/false_coordonate_two");
	cr_assert_eq(cor, NULL);
}
Test(get_coordonate, test2)
{
	coord_t **cor = get_coordonate("data/coordonate");
	int i = 0;

	cr_assert_neq(cor, NULL);
	while (cor[i] != NULL) {
		cr_assert_eq(cor[i]->size, 2);
		cr_assert_eq(cor[i]->pa->x, 2);
		cr_assert_eq(cor[i]->pa->y, 3);
		cr_assert_eq(cor[i]->pb->x, 3);
		cr_assert_eq(cor[i]->pb->y, 3);
		i++;
	}
	destroy_list_coord(cor);
}
