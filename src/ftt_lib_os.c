/**************************************************************************   */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_os.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:25:34 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 15:29:23 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ftt.h"
#include "criterion/assert.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libft_io.h>
#include <libft_mem.h>
#include <libft_os.h>
#include <libft_str.h>
#include <libft_arr.h>
#include <sys/wait.h>
#include <unistd.h>

#define T(a) Test(libft_os, a)

T(os_cmd_parse_echo_hello)
{
	t_os_exec *exc = ft_os_cmd_parse("echo hello", __environ);
	cr_assert_not_null(exc);
	cr_assert_(exc->exec_file);
}

