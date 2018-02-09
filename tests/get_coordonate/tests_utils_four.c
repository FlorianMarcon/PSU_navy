/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my.h"
coord_t	*create_ccoorr(void);
coord_t	*create_ccoorr_two(void);
linked_list_t	*create_list_point_by_coord(coord_t **cor);
int	put_coord_in_list_point(linked_list_t *list, coord_t *cor);

Test(put_coord_in_list_point, test1)
{
	coord_t *cor = create_ccoorr();
	linked_list_t *list = malloc(sizeof(*list));

	if (list != NULL && cor != NULL) {
		list->next = NULL;
		cr_assert_eq(put_coord_in_list_point(list, cor), 1);
	}
}

Test(put_coord_in_list_point, test2)
{
	coord_t *cor = create_ccoorr_two();
	linked_list_t *list = malloc(sizeof(*list));

	if (list != NULL && cor != NULL) {
		list->next = NULL;
		cr_assert_eq(put_coord_in_list_point(list, cor), 1);
	}
}
Test(create_list_point_by_coord, test1)
{
	coord_t **cor = malloc(sizeof(*cor) * 5);
	linked_list_t *list;

	cor[4] = NULL;
	cor[0] = create_ccoorr();
	cor[1] = create_ccoorr_two();
	cor[2] = create_ccoorr();
	cor[3] = create_ccoorr_two();
	list = create_list_point_by_coord(cor);
	cr_assert_neq(list, NULL);
}
