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

Test(libft_str, strlen_empty)
{
	cr_expect_eq(ft_strlen(""), 0);
}

Test(libft_str, strlen_easy)
{
	char *input = "987213 jlkj#,0AAAAA";
	cr_expect_eq(ft_strlen(input), strlen(input));
}

Test(libft_str, strchr_easy)
{
	int c = 'x';
	char *s = "examn_abcd";
	cr_assert_eq(ft_strchr(s, c), &s[1]);
}

Test(libft_str, strchr_not_found)
{
	int c = '?';
	char *s = "examn_abcd";
	char *result = ft_strchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

Test(libft_str, strchr_0_found)
{
	int c = '\0';
	char *s = "1234";
	char *result = ft_strchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

Test(libft_str, strrchr_easy)
{
	int c = 'x';
	char *s = "examn_abcd";
	cr_assert_eq(ft_strrchr(s, c), &s[1]);
}

Test(libft_str, strrchr_not_found)
{
	int c = '?';
	char *s = "examn_abcd";
	char *result = ft_strrchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

Test(libft_str, strrchr_0_found)
{
	int c = '\0';
	char *s = "1234";
	char *result = ft_strrchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

Test(libft_str, strlcpy_easy)
{
	char *src = "12345678";
	char *dest = (char *) ftt_malloc(20 * sizeof(char));
	ft_strlcpy(dest, src, 10);
	cr_assert_eq(strcmp(src, dest), 0);
}

Test(libft_str, strlcpy_smol_dest)
{
	char *src = "123456789";
	char *dest = (char *) ftt_malloc(2 * sizeof(char));
	cr_assert_eq(ft_strlcpy(dest, src, 2), 10);
}

Test(libft_str, strnstr_happy)
{
	char *haystack = "!x345689";
	char *needle = "345";
	cr_assert_eq(haystack + 2, ft_strnstr(haystack, needle, 9));
}

Test(libft_str, strnstr_not_happen)
{
	char *haystack = "ax3056789";
	char *needle = "35";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 9));
}

Test(libft_str, strnstr_out_of_range)
{
	char *haystack = "1jlkjkl56789";
	char *needle = "89";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 5));
}

Test(libft_str, strnstr_empty_large)
{
	const char *haystack = "";
	const char *needle = "89";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 5));
}

Test(libft_str, strnstr_close)
{
	const char *haystack = "a234";
	const char *needle = "23";
	cr_assert_eq(haystack + 1, ft_strnstr(haystack, needle, 3));
}

Test(libft_str, strnstr_simple_1)
{
	const char *haystack = "12";
	const char *needle = "2";
	cr_assert_eq(haystack + 1, ft_strnstr(haystack, needle, 4));
}

Test(libft_str, strnstr_empty_little)
{
	const char *haystack = "123456789";
	const char *needle = "";
	cr_assert_eq(haystack, ft_strnstr(haystack, needle, 5));
}

Test(libft_str, strnstr_man_page)
{
	const char	*largestring = "Foo Bar	Baz";
	const char	*smallstring = "Bar";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 4);
	cr_assert_eq(ptr, NULL);
}

Test(libft_str, atoi_ft)
{
	char *s = "42";
	cr_assert_eq(42, ft_atoi(s));
}

Test(libft_str, atoi_easy)
{
	char *s = "123";
	cr_assert_eq(123, ft_atoi(s));
}

Test(libft_str, atoi_zero)
{
	char *s = "0";
	cr_assert_eq(0, ft_atoi(s));
}

Test(libft_str, atoi_neg_easy)
{
	char *s = "-123";
	cr_assert_eq(-123, ft_atoi(s));
}

Test(libft_str, atoi_pre0_neg)
{
	char *s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

Test(libft_str, atoi_pre0_pov)
{
	char *s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

Test(libft_str, atoi_int_max)
{
	char *s = "-2147483648";
	cr_assert_eq(-2147483648, ft_atoi(s));
}

Test(libft_str, atoi_int_max_bs)
{
	char *s = "  -2147483648 jkljklj";
	cr_assert_eq(-2147483648, ft_atoi(s));
}

Test(libft_str, atoi_int_min)
{
	char *s = "2147483647";
	cr_assert_eq(2147483647, ft_atoi(s));
}

Test(libft_str, atoi_bs_afterwards)
{
	char *s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

