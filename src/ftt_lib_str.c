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

Test(libft_str, strlen_empty)
{
	cr_expect_eq(ft_strlen(""), 0);
}

Test(libft_str, strlen_easy)
{
	char *input = strdup("987213 jlkj#,0AAAAA");
	cr_expect_eq(ft_strlen(input), strlen(input));
}

Test(libft_strchr, strchr_easy)
{
	int c = 'x';
	char *s = "examn_abcd";
	cr_assert_eq(ft_strchr(s, c), &s[1]);
}

Test(libft_strchr, strchr_not_found)
{
	int c = '?';
	char *s = "examn_abcd";
	char *result = ft_strchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

Test(libft_strchr, strchr_0_found)
{
	int c = '\0';
	char *s = "1234";
	char *result = ft_strchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}

Test(libft_strrchr, strrchr_easy)
{
	int c = 'x';
	char *s = "examn_abcd";
	cr_assert_eq(ft_strrchr(s, c), &s[1]);
}

Test(libft_strrchr, strrchr_not_found)
{
	int c = '?';
	char *s = "examn_abcd";
	char *result = ft_strrchr(s, c);
	cr_assert_eq(result, NULL, "%p is not NULL, but %x :c", result, *result);
}

Test(libft_strrchr, strrchr_0_found)
{
	int c = '\0';
	char *s = "1234";
	char *result = ft_strrchr(s, c);
	cr_assert_eq(result, &s[4], "%p + 4 != %p", result, &result[4]);
}



