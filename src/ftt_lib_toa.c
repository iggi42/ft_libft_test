/**************************************************************************   */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_toa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:25:34 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 15:29:23 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftt.h"
#include "libft.h"
#include "libft_locale.h"
#include <limits.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdio.h>


#define T(a) Test(libft_toa, a)

T(ulto_bl_easy_0)
{
  unsigned long nb = 0;
  char *target = ftt_malloc(2 * sizeof(char));
  size_t result_size = ft_ultoa_bl(nb, target, 1, "01");
  cr_assert_eq(result_size, 1);
  target[1] = '\0';
  cr_assert_str_eq(target, "0");
  free(target);
}

T(ulto_bl_easy_1)
{
  unsigned long nb = 1;
  char *target = ftt_malloc(2 * sizeof(char));
  cr_assert_eq(ft_ultoa_bl(nb, target, 1, "01"), 1);
  target[1] = '\0';
  cr_assert_str_eq(target, "1");
  free(target);
}

T(ltoa_b_easy_pos)
{
  char *s;
  cr_assert_str_eq(s = ft_ultoa_b(4, FT_ALPHABET_DEC), "4");
  free(s);
}

T(ltoa_b_easy_42)
{
  char *s;
  cr_assert_str_eq(s = ft_ultoa_b(42, FT_ALPHABET_DEC), "42");
  free(s);
}

T(ltoa_b_easy_neg)
{
  char *s;
  cr_assert_str_eq(s = ft_ltoa_b(-4, FT_ALPHABET_DEC), "-4");
  free(s);
}

T(ltoa_b_zero)
{
  char *s;
  cr_assert_str_eq(s = ft_ltoa_b(0, FT_ALPHABET_DEC), "0");
  free(s);
}

T(ltoa_bl_easy_neg)
{
  cr_assert_eq(ft_ltoa_bl(-4, NULL, 0, FT_ALPHABET_DEC), 2);
}

T(ltoa_b_neg_min)
{
  char *expected = ft_str_alloc(20);
  sprintf(expected, "%ld", LONG_MIN);
  char *actual = ft_ltoa_b(LONG_MIN, FT_ALPHABET_DEC);
  cr_assert_str_eq(expected, actual);
  free(expected);
  free(actual);
}

T(ltoa_b_pos_max)
{
  char *expected = ft_str_alloc(20);
  sprintf(expected, "%ld", LONG_MAX);
  char *actual = ft_ultoa_b(LONG_MAX, FT_ALPHABET_DEC);
  cr_assert_str_eq(expected, actual);
  free(actual);
  free(expected);
}

T(itoa_simple)
{
  char *s;
	cr_assert_str_eq(s = ft_itoa(42),"42" ); free(s);
	cr_assert_str_eq(s = ft_itoa(-1), "-1"); free(s);
	cr_assert_str_eq(s = ft_itoa(0),"0"); free(s);
}

T(itoa_binary_base)
{
  char *s;
  cr_assert_str_eq(s = ft_itoa_b(1, "0X"), "X"); free(s);
  cr_assert_str_eq(s = ft_itoa_b(0, "0X"), "0"); free(s);
}

T(itoa_binary_base_larg)
{
  char *s;
  cr_assert_str_eq(s = ft_itoa_b(2, "01"), "10"); free(s);
  cr_assert_str_eq(s = ft_itoa_b(42, "01"), "101010"); free(s);
  cr_assert_str_eq(s = ft_itoa_b(4, "0X"), "X00"); free(s);
}

T(itoa_INT_MAX)
{
	char *s_int_max = (char *) malloc(15 * sizeof(char));
	char *s;
	snprintf(s_int_max, 15, "%d", INT_MAX);
	cr_assert_str_eq(s = ft_itoa(INT_MAX), s_int_max);
	free(s);
	free(s_int_max);
}

T(btoa_FF)
{
	char *s = ft_btoa(0xFF);
	cr_assert_str_eq(s, "FF");
	free(s);
}

T(btoa_A0)
{
	char *s = ft_btoa(0xA0);
	cr_assert_str_eq(s, "A0");
	free(s);
}

T(btoa_b_max_value)
{
  char *s;
  cr_assert_str_eq(s = ft_btoa_b(-1, "01"), "11111111");
  free(s);
}


// T(ptoa_null)
// {
// 	char *s = ft_ptoa(NULL);
// 	cr_assert_str_eq(s, "0x0000000000000000");
// }
