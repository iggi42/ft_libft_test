/**************************************************************************   */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:25:34 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 15:29:23 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft_io.h>
#include <libft_mem.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#define T(a) Test(libft_io, a)

T(printf_test)
{
	cr_redirect_stdout();
	ft_printf("Test, %s", NULL);
	FILE *stdout = cr_get_redirected_stdout();
	cr_assert(cr_file_match_str(stdout, "Test, (null)"));
}
