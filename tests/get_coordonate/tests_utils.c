/*
** EPITECH PROJECT, 2017
** get_coordonate
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_navy.h"
coord_t	**create_list_coord(void);
coord_t	**get_coordonate(char *path);

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
	cor = get_coordonate("data/coordonate");


//comprendre pourquoi celle la ne fonctionne pas

	cr_assert_neq(cor, NULL);
}
