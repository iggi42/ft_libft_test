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
#include "libft.h"
#include <limits.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdio.h>


#define T(a) Test(libft_toa, a)


T(ulto_bl_easy_0)
{
  unsigned long nb = 0;
  char *target = ftt_malloc(2 * sizeof(char));
  size_t result_size = ft_ulto_bl(nb, target, 1, "01");
  cr_assert_eq(result_size, 1);
  target[1] = '\0';
  cr_assert_str_eq(target, "0");
}


T(ulto_bl_easy_1)
{
  unsigned long nb = 1;
  char *target = ftt_malloc(2 * sizeof(char));
  size_t result_size = ft_ulto_bl(nb, target, 1, "01");
  cr_assert_eq(result_size, 1);
  target[1] = '\0';
  cr_assert_str_eq(target, "1");
}


T(ltoa_b_easy_pos)
{
  cr_assert_str_eq(ft_ultoa_b(4, DEC_ALPHABET), "4");
}


T(ltoa_b_easy_42)
{
  cr_assert_str_eq(ft_ultoa_b(42, DEC_ALPHABET), "42");
}

// T(ltoa_b_easy_neg)
// {
//   cr_assert_str_eq(ft_ultoa_b(-4, DEC_ALPHABET), "-4");
// }

// T(ltoa_b_neg_min)
// {
//   char buffer[100];
//   char *expected = (char *) &buffer;
//   sprintf(expected, "%ld", LONG_MIN);
//   char *actual = ft_ultoa_b(LONG_MIN, DEC_ALPHABET);
//   cr_assert_str_eq(expected, actual);
// }

T(ltoa_b_pos_max)
{
  char buffer[100];
  char *expected = (char *) &buffer;
  sprintf(expected, "%ld", LONG_MAX);
  char *actual = ft_ultoa_b(LONG_MIN, DEC_ALPHABET);
  cr_assert_str_eq(expected, actual);
}
