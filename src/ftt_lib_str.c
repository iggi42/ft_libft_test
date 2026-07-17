/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:25:34 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/09 17:36:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftt.h"
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <libft_str.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T(a) Test(libft_str, a)

T(strlen_empty)
{
	cr_expect_eq(ft_strlen(""), 0);
}

T(strlen_easy)
{
	char	*input;

	input = "987213 jlkj#,0AAAAA";
	cr_expect_eq(ft_strlen(input), strlen(input));
}

T(str_alloc_0)
{
	size_t	len;
	char	*result;

	len = 0;
	result = ft_str_alloc(len);
	cr_assert_eq(*(result + len), 0, "nope: actual string : [%s]\n", result);
	free(result);
}

T(str_alloc_10)
{
	size_t	len;
	char	*result;

	len = 10;
	result = ft_str_alloc(len);
	cr_assert_eq(*(result + len), 0, "nope: actual string : [%s]\n", result);
	free(result);
}

T(strchr_easy)
{
	int		c;
	char	*s;

	c = 'x';
	s = "examn_abcd";
	cr_assert_eq(ft_strchr(s, c), &s[1]);
}

T(strchr_not_found)
{
	int		c;
	char	*s;
	char	*result;

	c = '?';
	s = "examn_abcd";
	result = ft_strchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

T(strchr_0_found)
{
	char	*s;
	char	*result;

	s = "1234";
	result = ft_strchr(s, '\0');
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

T(strrchr_easy)
{
	int		c;
	char	*s;

	c = 'x';
	s = "examn_abcd";
	cr_assert_eq(ft_strrchr(s, c), &s[1]);
}

T(strrchr_not_found)
{
	int		c;
	char	*s;
	char	*result;

	c = '?';
	s = "examn_abcd";
	result = ft_strrchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

T(strrchr_0_found)
{
	int		c;
	char	*s;
	char	*result;

	c = '\0';
	s = "1234";
	result = ft_strrchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

T(strlcpy_easy)
{
	char	*src;
	char	*dest;

	src = "12345678";
	dest = (char *)ftt_malloc(20 * sizeof(char));
	ft_strlcpy(dest, src, 10);
	cr_assert_str_eq(src, dest);
	free(dest);
}

T(strlcpy_close)
{
	char	*src;
	char	*dest;

	src = "12345678";
	dest = (char *)ftt_malloc(9 * sizeof(char));
	ft_strlcpy(dest, src, 9);
	cr_assert_str_eq(src, dest);
	free(dest);
}

// T(strlcpy_smol_dest)
// {
// 	char *src = "123456789";
// 	char *dest = (char *) ftt_malloc(2 * sizeof(char));
// 	cr_assert_eq(ft_strlcpy(dest, src, 2), 10);
// }

// T(strlcat_easy)
// {
// 	char	*src;
// 	char	*dest;
// 	int		result;

// 	src = "qwertzuiop";
// 	dest = strdup("abc\0;123456789;123456789");
// 	result = ft_strlcat(dest, src, 14);
// 	cr_assert_eq(result, 13, "dest: \"%d\"", result);
// 	cr_assert_str_eq(dest, "abcqwertzuiop");
// 	free(dest);
// }

// strlcat with dst buffer too small
/*
T(strlcat_too_small)
{
	char	*src;
	char	*dest;
	int		result;

	src = "qwertzuiop";
	dest = strdup("jk\0 234567");
	result = ft_strlcat(dest, src, 10);
	cr_assert_eq(result, 12, "result: %d", result);
	cr_assert_str_eq("jk", dest, "dest: \"%s\"", dest); // string hasn't changed
}
*/

// // strlcat with dst buffer too small
// T(strlcat_too_small)
// {
// 	char *src = "qwertzuiop";
// 	char *dest = strdup("jk\0 234567");
//   int result = ft_strlcat(dest, src, 10);
// 	cr_assert_eq(result, 12, "result: %d", result);
// 	cr_assert_str_eq("jk", dest, "dest: \"%s\"", dest); // string hasn't changed
// }

T(strnstr_happy)
{
	char	*haystack;
	char	*needle;

	haystack = "!x345689";
	needle = "345";
	cr_assert_eq(haystack + 2, ft_strnstr(haystack, needle, 9));
}

T(strnstr_not_happen)
{
	char	*haystack;
	char	*needle;

	haystack = "ax3056789";
	needle = "35";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 9));
}

T(strnstr_out_of_range)
{
	char	*haystack;
	char	*needle;

	haystack = "1jlkjkl56789";
	needle = "89";
	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 5));
}

T(strnstr_empty_large)
{
	const char	*haystack = "";
	const char	*needle = "89";

	cr_assert_eq(NULL, ft_strnstr(haystack, needle, 5));
}

T(strnstr_close)
{
	const char	*haystack = "a234";
	const char	*needle = "23";

	cr_assert_eq(haystack + 1, ft_strnstr(haystack, needle, 3));
}

T(strnstr_simple_1)
{
	const char	*haystack = "12";
	const char	*needle = "2";

	cr_assert_eq(haystack + 1, ft_strnstr(haystack, needle, 4));
}

T(strnstr_empty_little)
{
	const char	*haystack = "123456789";
	const char	*needle = "";

	cr_assert_eq(haystack, ft_strnstr(haystack, needle, 5));
}

T(strnstr_man_page)
{
	const char	*largestring = "Foo Bar	Baz";
	const char	*smallstring = "Bar";

	cr_assert_null(ft_strnstr(largestring, smallstring, 4));
}

T(substr_easy)
{
	const char	*base = "12345678";
	char		*result;

	result = ft_substr(base, 0, 3);
	cr_assert_eq(strncmp("123", result, 4), 0, "\"%s\" is not \"123\"", result);
	cr_assert_eq(strlen(result), 3);
	free(result);
}

T(substr_size_too_large)
{
	const char	*base = "1";
	char		*result;

	result = ft_substr(base, 0, 3);
	cr_assert_eq(strncmp("1", result, 3), 0, "\"%s\" is not \"1\"", result);
	cr_assert_eq(strlen(result), 1);
	free(result);
}

T(substr_start_too_large)
{
	const char	*base = "";
	char		*result;

	result = ft_substr(base, 1, 3);
	cr_assert_eq(strncmp("", result, 3), 0, "\"%s\" is not an empty string",
		result);
	cr_assert_eq(strlen(result), 0);
	free(result);
}

T(substr_start_too_large2)
{
	const char	*base = "zxy abc efg ";
	char		*result;

	result = ft_substr(base, 13, 3);
	cr_assert_eq(strncmp("", result, 3), 0, "\"%s\" is not an empty string",
		result);
	cr_assert_eq(strlen(result), 0);
	free(result);
}

T(substr_middle)
{
	const char	*base = "zxy abc efg ";
	char		*result;

	result = ft_substr(base, 4, 3);
	cr_assert_eq(strncmp("abc", result, 3), 0, "\"%s\" is not an empty string",
		result);
	cr_assert_eq(strlen(result), 3);
	free(result);
}

T(substr_last_char)
{
	const char	*base = "abc1";
	char		*result;

	result = ft_substr(base, 3, 3);
	cr_assert_eq(strncmp("1", result, 3), 0, "\"%s\" the last char of \"%s\" ",
		result, base);
	cr_assert_eq(strlen(result), 1);
	free(result);
}

T(strjoin_easy)
{
	char	*s;

	cr_assert_str_eq(s = ft_strjoin("4", "2"), "42");
	free(s);
}

T(strjoin_empty)
{
	char	*s;

	cr_assert_str_eq(s = ft_strjoin("", ""), "");
	free(s);
}

T(strjoin_smoll)
{
	char	*s;

	cr_assert_str_eq(s = ft_strjoin("a", ""), "a");
	free(s);
}

T(strtrim_easy)
{
	char	*s;

	cr_assert_str_eq(s = ft_strtrim("0Eins1Zwei2Drei3Fier4", "0123456789"),
		"Eins1Zwei2Drei3Fier");
	free(s);
}

T(strtrim_empty)
{
	const char	*set = "0123456789";
	const char	*s1 = "";
	char		*result;

	result = ft_strtrim(s1, set);
	cr_assert_str_eq(result, "");
	free(result);
}

T(strtrim_empty2)
{
	const char	*set = "0123456789";
	const char	*s1 = "jkjk";
	char		*result;

	result = ft_strtrim(s1, set);
	cr_assert_str_eq("jkjk", result);
	free(result);
}

T(split_easy)
{
	const char	*input = "01 232 45 a6a7a 89";
	char		**result;
	size_t		result_length;

	result = ft_split(input, ' ');
	cr_assert_neq(result, NULL);
	cr_assert_str_eq(result[0], "01");
	cr_assert_str_eq(result[1], "232");
	cr_assert_str_eq(result[2], "45");
	cr_assert_str_eq(result[3], "a6a7a");
	cr_assert_str_eq(result[4], "89");
	result_length = ftt_array_lenth((const void *)result, sizeof(char *));
	cr_assert_eq(result_length, 5, "actual length %i\n", (int)result_length);
	ftt_array_free((const void **)result);
}

// ATOI and friends
T(atoi_ft)
{
	char	*s;

	s = "42";
	cr_assert_eq(42, ft_atoi(s));
}

T(atoi_easy)
{
	char	*s;

	s = "123";
	cr_assert_eq(123, ft_atoi(s));
}

T(atoi_zero)
{
	char	*s;

	s = "0";
	cr_assert_eq(0, ft_atoi(s));
}

T(atoi_neg_easy)
{
	char	*s;

	s = "-123";
	cr_assert_eq(-123, ft_atoi(s));
}

T(atoi_pre0_neg)
{
	char	*s;

	s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

T(atoi_pre0_pov)
{
	char	*s;

	s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

T(atoi_int_max)
{
	char	*s;

	s = "-2147483648";
	cr_assert_eq(-2147483648, ft_atoi(s));
}

T(atoi_int_max_bs)
{
	char	*s;

	s = "  -2147483648 jkljklj";
	cr_assert_eq(-2147483648, ft_atoi(s));
}

T(atoi_int_min)
{
	char	*s;

	s = "2147483647";
	cr_assert_eq(2147483647, ft_atoi(s));
}

T(atoi_bs_afterwards)
{
	char	*s;

	s = "-00123";
	cr_assert_eq(-123, ft_atoi(s));
}

static int is_sixseven(int c)
{
	return ((char) c) == '6' || ((char) c) == '7';
}

T(strnxt_easy)
{
	char *s;
	s = "012385778";

	cr_assert_eq(ft_strnxt(s, is_sixseven), s + 6);
}

T(strnxt_empty_str)
{
	char *s;
	s = "";

	cr_assert_eq(ft_strnxt(s, is_sixseven), NULL);
}

T(strnxt_not_found)
{
	char *s;
	s = "82398djkljdaf";

	cr_assert_eq(ft_strnxt(s, is_sixseven), NULL);
}


T(str2l_0)
{
	char *s = "0";
	long result;
	cr_assert_eq(ft_str2l(s, &result), ft_strlen(s));
	cr_assert_eq(result, 0,"result is %ld instead of 0", result );
}


T(str2l_neg0)
{
	char *s = "-0";
	long result;
	cr_assert_eq(ft_str2l(s, &result), ft_strlen(s));
	cr_assert_eq(result, 0,"result is %ld instead of 0", result );
}

T(str2l_42_invalid_str)
{
	char *s = "jkl351hhjadf";
	long result;
	cr_assert_eq(ft_str2l(s, &result), 0);
}

T(str2l_42_extra_str)
{
	char *s = "42jkl";
	long result;
	cr_assert_eq(ft_str2l(s, &result), ft_strlen(s) - 3);
	cr_assert_eq(result, 42,"result is %ld instead of 42", result );
}

T(str2l_max_long)
{
	char *s = "9223372036854775807";
	long result;
	size_t read = ft_str2l(s, &result);

	cr_assert_eq(read, ft_strlen(s), "only read %ld chars instead of %ld\n", read, ft_strlen(s));
	cr_assert_eq(result, LONG_MAX,"result is %ld instead of long max (%ld)", result, LONG_MAX );
}

T(str2l_max_long_1overflow)
{
	char *s = "9223372036854775808";
	long result;
	size_t read = ft_str2l(s, &result);

	cr_assert_eq(read, ft_strlen(s), "only read %ld chars instead of %ld\n", read, ft_strlen(s));
}

T(str2l_min_long)
{
    char *s = "-9223372036854775808";

	long result;
	cr_assert_eq(ft_str2l(s, &result), ft_strlen(s));
	cr_assert_eq(result, LONG_MIN, "result is %ld instead of long min (%ld)", result, LONG_MIN);
}


T(str2l_min_long_1underflow)
{
    char *s = "-9223372036854775809";

	long result;
	cr_assert_eq(ft_str2l(s, &result), 0);
}

T(str2l_2xmin_long_neg_overflow_test)
{
	char *s = "-18446744073709551616";
	long result;
	cr_assert_eq(ft_str2l(s, &result), 0);
}

T(str2l_2xmax_long_pos_overflow_test)
{
	char *s = "18446744073709551616";
	long result;
	cr_assert_eq(ft_str2l(s, &result), 0);
}

T(str2d_min_long)
{
    char *s = "-9223372036854775808/1";

	double result;
	cr_assert_eq(ft_str2d(s, &result), ft_strlen(s));
	cr_assert_eq(result, (double) LONG_MIN, "result is %f instead of %f", result, (double) LONG_MIN);
}

T(str2d_min_ns)
{
    char *s = "-9223372036854775808/-9223372036854775808";

	double result;
	cr_assert_eq(ft_str2d(s, &result), ft_strlen(s));
	cr_assert_eq(result, 1.0, "result is %f instead of %f", result, 1.0);
}

T(str2d_42)
{
    char *s = "420/10";

	double result;
	cr_assert_eq(ft_str2d(s, &result), ft_strlen(s));
	cr_assert_eq(result, 42.0, "result is %f instead of (%f)", result, 42.0);
}

T(str2d_1337)
{
    char *s = "-jk420.10";

	double result;
	cr_assert_eq(ft_str2d(s, &result), false);
}

T(str2d_1337_2)
{
    char *s = "420.10";

	double result;
	cr_assert_eq(ft_str2d(s, &result), false);
}

T(str_eq_emp)
{
	cr_assert(ft_str_eq("", ""), "two empty strings should be equal");
}

T(str_eq_joa)
{
	cr_assert(ft_str_eq("joa", "joa"), "two \"joa\" strings should be equal");
}


T(str_eq_joa0)
{
	cr_assert(ft_str_eq("joa\0joa", "joa"), "two \"joa\" strings should be equal");
}

T(str_eq_joan)
{
	cr_assert_not(ft_str_eq("joan", "joa"), "\"joan\" != \"joa\"");
}


T(str_sw_empty_empty)
{
	cr_assert(ft_str_sw("", ""), "\"\" starts with \"\"");
}

T(str_sw_joajjlk_joa)
{
	cr_assert(ft_str_sw("joajlkjlk", "joa"));
}

T(str_sw_joa_joa)
{
	cr_assert(ft_str_sw("joa", "joa"));
}

T(str_sw_n_jjoa_joa)
{
	cr_assert_not(ft_str_sw("jjoa", "joa"));
}

T(str_sw_n_jjoa_jjjjoa)
{
	cr_assert_not(ft_str_sw("jjoa", "jjjoa"));
}
