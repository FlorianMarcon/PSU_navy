/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_navy.h"
#include "my.h"
point_t	*translate_coordonate(char *msg);
void	translate_coordonate_in_msg(point_t *p);

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

Test(translate_coordonate_in_msg, test1)
{
	point_t p = {0, 0, 0};

	cr_redirect_stdout();
	translate_coordonate_in_msg(&p);
	cr_assert_stdout_eq_str("A1:	");
}
