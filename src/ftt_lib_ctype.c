/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_ctype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:12:15 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/08 14:26:56 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftt.h"
#include <criterion/criterion.h>
#include <stdio.h>
#include <libft.h>

#define EOF_Test(target) Test(libft_ctype, target) { cr_assert(target(EOF) == 0); }
EOF_Test(ft_isalpha)
EOF_Test(ft_isdigit)
EOF_Test(ft_isalnum)
EOF_Test(ft_isascii)
EOF_Test(ft_isprint)

Test(libft_ctype, ctype_positive)
{
	cr_expect_eq(ft_isalpha('A'), 1);
	cr_expect_eq(ft_isdigit('4'), 1);
	cr_expect_eq(ft_isdigit('1'), 1);
	cr_expect_eq(ft_isdigit('9'), 1);
	cr_expect_eq(ft_isalnum('a'), 1);
	cr_expect_eq(ft_isalnum('0'), 1);
	cr_expect_eq(ft_isprint('['), 1);
	// cr_expect_eq(ft_isprint('ä'), 1);
}

Test(libft_ctype, isascii)
{
	cr_expect_eq(ft_isascii('\x00'), 1);
	cr_expect_eq(ft_isascii('\x7F'), 1);
	cr_expect_eq(ft_isascii('\x80'), 0);
}

Test(libft_ctype, change_case)
{
	cr_expect_eq(ft_tolower('A'), 'a');
	cr_expect_eq(ft_tolower('%'), '%');

	cr_expect_eq(ft_toupper('a'), 'A');
	cr_expect_eq(ft_toupper('%'), '%');

	// ???
	cr_expect_eq(ft_toupper(-1), -1);
}
