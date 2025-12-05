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
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <string.h>
#include <limits.h>

#define T(a) Test(libft_str, a)

T(strlen_empty)
{
	cr_expect_eq(ft_strlen(""), 0);
}

T(strlen_easy)
{
	char *input = "987213 jlkj#,0AAAAA";
	cr_expect_eq(ft_strlen(input), strlen(input));
}

T(str_alloc_0)
{
	size_t len = 0;
	char *result = ft_str_alloc(len);
	cr_assert_eq(*(result + len), 0);
	free(result);
}

T(str_alloc_10)
{
	size_t len = 10;
	char *result = ft_str_alloc(len);
	cr_assert_eq(*(result + len), 0);
	free(result);
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
	cr_assert_str_eq(src, dest);
}

T(strlcpy_close)
{
	char *src = "12345678";
	char *dest = (char *) ftt_malloc(9 * sizeof(char));
	ft_strlcpy(dest, src, 9);
	cr_assert_str_eq(src, dest);
}

// T(strlcpy_smol_dest)
// {
// 	char *src = "123456789";
// 	char *dest = (char *) ftt_malloc(2 * sizeof(char));
// 	cr_assert_eq(ft_strlcpy(dest, src, 2), 10);
// }

T(strlcat_easy)
{
	char *src = "qwertzuiop";
	char *dest = strdup("abc\0;123456789;123456789");
  int result = ft_strlcat(dest, src, 12);
	cr_assert_eq(result , 13, "expected 13, got %d ", result);
	cr_assert_str_eq("abcqwertzui", dest);
}

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

T(substr_easy)
{
 const char *base = "12345678";
 const char *result = ft_substr(base, 0, 3);
 cr_assert_eq(strncmp("123", result, 4), 0, "\"%s\" is not \"123\"", result);
 cr_assert_eq(strlen(result), 3);
}

T(substr_size_too_large)
{
 const char *base = "1";
 const char *result = ft_substr(base, 0, 3);
 cr_assert_eq(strncmp("1", result, 3), 0, "\"%s\" is not \"1\"", result);
 cr_assert_eq(strlen(result), 1);
}

T(substr_start_too_large)
{
 const char *base = "";
 const char *result = ft_substr(base, 1, 3);
 cr_assert_eq(strncmp("", result, 3), 0, "\"%s\" is not an empty string", result);
 cr_assert_eq(strlen(result), 0);
}

T(substr_start_too_large2)
{
 const char *base = "zxy abc efg ";
 const char *result = ft_substr(base, 13, 3);
 cr_assert_eq(strncmp("", result, 3), 0, "\"%s\" is not an empty string", result);
 cr_assert_eq(strlen(result), 0);
}

T(substr_middle)
{
 const char *base = "zxy abc efg ";
 const char *result = ft_substr(base, 4, 3);
 cr_assert_eq(strncmp("abc", result, 3), 0, "\"%s\" is not an empty string", result);
 cr_assert_eq(strlen(result), 3);
}
	
T(substr_last_char)
{
 const char *base = "abc1";
 const char *result = ft_substr(base, 3, 3);
 cr_assert_eq(strncmp("1", result, 3), 0, "\"%s\" the last char of \"%s\" ", result, base);
 cr_assert_eq(strlen(result), 1);
}

T(strjoin_easy)
{
 const char *base = ft_strjoin("4", "2");
 cr_assert_str_eq(base, "42");
}
 
T(strjoin_empty)
{
 const char *base = ft_strjoin("", "");
 cr_assert_str_eq(base, "");
}

T(strjoin_smoll)
{
 const char *base = ft_strjoin("a", "");
 cr_assert_str_eq(base, "a");
}

T(strtrim_easy)
{
 const char *set = "0123456789";
 const char *s1 = "0Eins1Zwei2Drei3Fier4";
 const char *result = ft_strtrim(s1, set);
 cr_assert_str_eq("Eins1Zwei2Drei3Fier", result);
}

T(strtrim_empty)
{
 const char *set = "0123456789";
 const char *s1 = "";
 const char *result = ft_strtrim(s1, set);
 cr_assert_str_eq(result, "");
}

T(strtrim_empty2)
{
 const char *set = "0123456789";
 const char *s1 = "jkjk";
 const char *result = ft_strtrim(s1, set);
 cr_assert_str_eq("jkjk", result);
}

T(split_easy)
{
 const char *input = "01 23 45 67 89";
 char **result = ft_split(input, ' ');
 cr_assert_neq(result, NULL);
 cr_assert_str_eq(result[0], "01");
 cr_assert_str_eq(result[1], "23");
 cr_assert_str_eq(result[2], "45");
 cr_assert_str_eq(result[3], "67");
 cr_assert_str_eq(result[4], "89");
 size_t result_length = ftt_array_lenth((const void *) result, sizeof(char *));
 cr_assert_eq(result_length, 5, "actual length %i\n", (int) result_length);
}

// ATOI and friends
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
