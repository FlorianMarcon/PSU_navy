/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_navy.h"
#include "my.h"
point_t	*translate_coordonate(char *msg);

Test(translate_coordonate, test1)
{
	cr_assert_eq(translate_coordonate("B"), NULL);
	cr_assert_eq(translate_coordonate("B25"), NULL);
	cr_assert_eq(translate_coordonate("B!"), NULL);
	cr_assert_eq(translate_coordonate("B9"), NULL);
	cr_assert_eq(translate_coordonate("K5"), NULL);
	cr_assert_eq(translate_coordonate("!9"), NULL);
	cr_assert_neq(translate_coordonate("A1"), NULL);
	cr_assert_neq(translate_coordonate("H8"), NULL);
}
Test(translate_coordonate, test2)
{
	point_t *p = NULL;

	p = translate_coordonate("A1");
	cr_assert_eq(p->x, 0);
	cr_assert_eq(p->x, 0);
	free(p);
	p = translate_coordonate("H8");
	cr_assert_eq(p->x, 7);
	cr_assert_eq(p->x, 7);
	free(p);
}
