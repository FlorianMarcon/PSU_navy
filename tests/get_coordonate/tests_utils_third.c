/*
** EPITECH PROJECT, 2017
** test
** File description:
** create_list_point_by_coord
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my.h"
#include "my_printf.h"
int	add_point_list(linked_list_t *list, int x, int y, char c);
int	first_put_coord_in_list_point(linked_list_t *list, coord_t *cor);
int	second_put_coord_in_list_point(linked_list_t *list, coord_t *cor);

coord_t	*create_ccoorr(void)
{
	coord_t *cor = malloc(sizeof(*cor));
	point_t *pa = malloc(sizeof(*pa));
	point_t *pb = malloc(sizeof(*pb));

	if (cor == NULL || pa == NULL || pb == NULL)
		return (NULL);
	pa->x = 0;
	pa->y = 0;
	pb->x = 0;
	pb->y = 1;
	cor->pa = pa;
	cor->pb = pb;
	cor->size = 2;
	return (cor);
}
coord_t	*create_ccoorr_two(void)
{
	coord_t *cor = malloc(sizeof(*cor));
	point_t *pa = malloc(sizeof(*pa));
	point_t *pb = malloc(sizeof(*pb));

	if (cor == NULL || pa == NULL || pb == NULL)
		return (NULL);
	pa->x = 0;
	pa->y = 0;
	pb->x = 1;
	pb->y = 0;
	cor->pa = pa;
	cor->pb = pb;
	cor->size = 2;
	return (cor);
}
Test(add_point_list, test1)
{
	linked_list_t *list = malloc(sizeof(*list));
	linked_list_t *tmp = NULL;
	point_t *p;

	list->next = NULL;
	cr_assert_eq(add_point_list(list, 2, 2, '1'), 1);
	cr_assert_eq(add_point_list(tmp, 2, 2, '1'), -1);
	tmp = list->next;
	cr_assert_neq(tmp->data, NULL);
	p = (point_t *)(tmp->data);
	cr_assert_eq(p->x, 2);
	cr_assert_eq(p->y, 2);
	cr_assert_eq(p->value, '1');
}
Test(first_put_coord_in_list_point, test1)
{
	linked_list_t *list = malloc(sizeof(*list));
	coord_t *cor = create_ccoorr();
	point_t *p = NULL;

	if (cor != NULL) {
		cr_assert_eq(first_put_coord_in_list_point(NULL, cor), -1);
		cr_assert_eq(first_put_coord_in_list_point(list, cor), 1);
		list = list->next;
		cr_assert_eq(len_list(list), cor->size);
		p = (point_t *)(list->data);
		cr_assert_eq(p->x, 0);
		cr_assert_eq(p->y, 0);
		p = (point_t *)(list->next->data);
		cr_assert_eq(p->x, 0);
		cr_assert_eq(p->y, 1);
		cr_assert_eq(list->next->next, NULL);
	}
}

Test(second_put_coord_in_list_point, test1)
{
	linked_list_t *list = malloc(sizeof(*list));
	coord_t *cor = create_ccoorr_two();
	point_t *p = NULL;

	if (cor != NULL) {
		cr_assert_eq(second_put_coord_in_list_point(NULL, cor), -1);
		cr_assert_eq(second_put_coord_in_list_point(list, cor), 1);
		list = list->next;
		my_printf("len_list %i\n", len_list(list));
		cr_assert_eq(len_list(list), cor->size);
		p = (point_t *)(list->data);
		cr_assert_eq(p->x, 0);
		cr_assert_eq(p->y, 0);
		p = (point_t *)(list->next->data);
		cr_assert_eq(p->x, 1);
		cr_assert_eq(p->y, 0);
		cr_assert_eq(list->next->next, NULL);
	}
}
