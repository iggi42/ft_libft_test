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
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libft_io.h>
#include <libft_mem.h>
#include <libft_os.h>
#include <libft_str.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define T(a) Test(libft_os, a)

T(spawn_os_not_null)
{
	int res;
	int pid = ft_spawn_cmd("true", __environ, NULL);
	cr_assert_gt(pid, 0);
	waitpid(pid, &res, 0);
}

T(spawn_os_read_stdout)
{
	// int res;
	int pipes[2];
	char *s = "echo hello";
	int pid = ft_spawn_cmd(s, __environ, (int **) &pipes);
	cr_assert_gt(pid, 0);
	// waitpid(pid, &res, 0);
	char *l = ft_gnl(pipes[0]);
	cr_assert_str_eq(l, s);
	close(pipes[0]);
	close(pipes[1]);
}
