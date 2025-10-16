/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:25:34 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/08 14:25:54 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>
#include <libft.h>
#include <string.h>
#include <limits.h>

#define T(a) Test(libft2_str2, a)

T(strlen_empty)
{
	cr_expect_eq(ft_strlen(""), 0);
}

T(strlen_easy)
{
	char *input = "987213 jlkj#,0AAAAA";
	cr_expect_eq(ft_strlen(input), strlen(input));
}

T(strchr_easy)
{
	int c = 'x';
	char *s = "examn_abcd";
	cr_assert_eq(ft_strchr(s, c), &s[1]);
}

T(strchr_not_found)
{
	int c = '?';
	char *s = "examn_abcd";
	char *result = ft_strchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

T(strchr_0_found)
{
	int c = '\0';
	char *s = "1234";
	char *result = ft_strchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

T(strrchr_easy)
{
	int c = 'x';
	char *s = "examn_abcd";
	cr_assert_eq(ft_strrchr(s, c), &s[1]);
}

T(strrchr_not_found)
{
	int c = '?';
	char *s = "examn_abcd";
	char *result = ft_strrchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

T(strrchr_0_found)
{
	int c = '\0';
	char *s = "1234";
	char *result = ft_strrchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

T(strlcpy_easy)
{
	char *src = "12345678";
	char *dest = (char *) ftt_malloc(20 * sizeof(char));
	ft_strlcpy(dest, src, 10);
	cr_assert_eq(strcmp(src, dest), 0);
}

T(strlcpy_smol_dest)
{
	char *src = "123456789";
	char *dest = (char *) ftt_malloc(2 * sizeof(char));
	cr_assert_eq(ft_strlcpy(dest, src, 2), 10);
}

T(strnstr_happy)
{
	char *haystack = "!x345689";
	char *needle = "345";
	cr_assert_eq(haystack + 2, ft_strnstr(haystack, needle, 9));
}

T(strnstr_not_happen)
{
	char *haystack = "ax3056789";
	char *needle = "35";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 9));
}

T(strnstr_out_of_range)
{
	char *haystack = "1jlkjkl56789";
	char *needle = "89";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 5));
}

T(strnstr_empty_large)
{
	const char *haystack = "";
	const char *needle = "89";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 5));
}

T(strnstr_close)
{
	const char *haystack = "a234";
	const char *needle = "23";
	cr_assert_eq(haystack + 1, ft_strnstr(haystack, needle, 3));
}

T(strnstr_simple_1)
{
	const char *haystack = "12";
	const char *needle = "2";
	cr_assert_eq(haystack + 1, ft_strnstr(haystack, needle, 4));
}

T(strnstr_empty_little)
{
	const char *haystack = "123456789";
	const char *needle = "";
	cr_assert_eq(haystack, ft_strnstr(haystack, needle, 5));
}

T(strnstr_man_page)
{
	const char	*largestring = "Foo Bar	Baz";
	const char	*smallstring = "Bar";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 4);
	cr_assert_eq(ptr, NULL);
}

T(atoi_ft)
{
	char *s = "42";
	cr_assert_eq(42, ft_atoi(s));
}

T(atoi_easy)
{
	char *s = "123";
	cr_assert_eq(123, ft_atoi(s));
}

T(atoi_zero)
{
	char *s = "0";
	cr_assert_eq(0, ft_atoi(s));
}

T(atoi_neg_easy)
{
	char *s = "-123";
	cr_assert_eq(-123, ft_atoi(s));
}

T(atoi_pre0_neg)
{
	char *s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

T(atoi_pre0_pov)
{
	char *s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

T(atoi_int_max)
{
	char *s = "-2147483648";
	cr_assert_eq(-2147483648, ft_atoi(s));
}

T(atoi_int_max_bs)
{
	char *s = "  -2147483648 jkljklj";
	cr_assert_eq(-2147483648, ft_atoi(s));
}

T(atoi_int_min)
{
	char *s = "2147483647";
	cr_assert_eq(2147483647, ft_atoi(s));
}

T(atoi_bs_afterwards)
{
	char *s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

