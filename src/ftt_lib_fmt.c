#include "../include/ftt.h"
#include "libft.h"
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <limits.h>
#include <stdio.h>

#define T(a) Test(libft_fmt, a)

T(str_hello)
{
	char	*template;
	char	*result;

	template = "hello\n";
	result = ft_fmt_str(template);
	cr_assert_str_eq(result, template);
	free(result);
}

T(str_empty)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str(""), "");
	free(s);
}

T(str_op_c)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("4%c2", '-'), "4-2");
	free(s);
}

T(str_op_s)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("hello [%s]", "42"), "hello [42]");
	free(s);
}

T(str_op_d)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("hello [%d]", 42), "hello [42]");
	free(s);
}

T(str_op_i)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("answer: %i", 10), "answer: 10");
	free(s);
}

T(str_op_u)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("unsigned decimal answer: %u", INT_MIN),
		"unsigned decimal answer: 2147483648");
	free(s);
}

T(str_op_escape)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("answer: %%"), "answer: %");
	free(s);
}

T(str_op_u_0)
{
	char *s;
	cr_assert_str_eq(s =ft_fmt_str("unsigned decimal answer: %u", 0),
		"unsigned decimal answer: 0");
	free(s);
}

T(str_op_x_dead_beef)
{
	char *s;
	cr_assert_str_eq(s = ft_fmt_str("lower hex: %x", 0xdeadbeef),
		"lower hex: deadbeef");
	free(s);
}


T(str_op_X_bad_idea)
{
	char *s;
	cr_assert_str_eq(
		s = ft_fmt_str("upper hex: %X", 0xbad1dea),
		"upper hex: BAD1DEA"
	);
	free(s);
}


T(str_op_p_null)
{
	char *s;
	cr_assert_str_eq(
	  s = ft_fmt_str("null: %p !", NULL),
		"null: (nil) !"
	);
	free(s);
}

T(str_op_p_sprintf)
{
	char sprintf_result[100];
	char *s;
	sprintf_result[0] = 'w';
	sprintf(sprintf_result, "p: %p !", &sprintf_result);
	cr_assert_str_eq(
	  s = ft_fmt_str("p: %p !", &sprintf_result),
	  (char *) &sprintf_result
	);
	free(s);
}


// ft_printf("just a %%\n");
