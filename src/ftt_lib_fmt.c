#include "../include/ftt.h"
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <limits.h>
#include <stdio.h>
#include <libft_str.h>

#define T(a) Test(libft_fmt, a)

T(str_hello)
{
	char	*template;
	char	*result;

	template = "hello\n";
	result = ft_strf(template);
	cr_assert_str_eq(result, template);
	free(result);
}

T(str_empty)
{
	char *s;
	cr_assert_str_eq(s = ft_strf(""), "");
	free(s);
}

T(str_op_c)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("4%c2", '-'), "4-2");
	free(s);
}

T(str_op_s)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("hello [%s]", "42"), "hello [42]");
	free(s);
}

T(str_op_s_NULL)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("hello [%s]", (char *) NULL), "hello [(null)]");
	free(s);
}

T(str_op_d)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("hello [%d]", 42), "hello [42]");
	free(s);
}

T(str_op_i)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("answer: %i", 10), "answer: 10");
	free(s);
}

T(str_op_u)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("unsigned decimal answer: %u", INT_MIN),
		"unsigned decimal answer: 2147483648");
	free(s);
}

T(str_op_escape)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("answer: %%"), "answer: %");
	free(s);
}

T(str_op_u_0)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("unsigned decimal answer: %u", 0),
		"unsigned decimal answer: 0");
	free(s);
}

T(str_op_x_dead_beef)
{
	char *s;
	cr_assert_str_eq(s = ft_strf("lower hex: %x", 0xdeadbeef),
		"lower hex: deadbeef");
	free(s);
}

T(str_op_X_bad_idea)
{
	char *s;
	cr_assert_str_eq(
		s = ft_strf("upper hex: %X", 0xbad1dea),
		"upper hex: BAD1DEA"
	);
	free(s);
}

T(str_op_p_null)
{
	char *s;
	cr_assert_str_eq(
	  s = ft_strf("null: %p !", NULL),
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
	  s = ft_strf("p: %p !", &sprintf_result),
	  (char *) &sprintf_result
	);
	free(s);
}
