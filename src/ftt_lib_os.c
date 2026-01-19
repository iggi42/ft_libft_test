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
#include <sys/wait.h>
#include <unistd.h>

#define T(a) Test(libft_os, a)

T(spawn_cmd_not_null)
{
	int	res;
	int	pid;

	pid = ft_spawn_cmd("true", __environ, NULL);
	cr_assert_gt(pid, 0);
	waitpid(pid, &res, 0);
}

T(spawn_read_stdout)
{
	t_os_proc	*proc;
	char test[10];

	test[6] = 0;
	proc = ft_os_spawn("echo -n test42", __environ);
	cr_assert_not_null(proc);
	cr_assert_eq(read(proc->stdout, test, 9), 6, "proc-stdout is %d", proc->stdout);
	cr_assert_str_eq(test, "test42");
}

T(spawn_pipe_thru)
{
	t_os_proc	*proc;
	char test[10];

	test[6] = 0;
	proc = ft_os_spawn("cat -n -", __environ);
	cr_assert_not_null(proc);
	ft_write(proc->stdin, "t1\n", 3);
	cr_assert_eq(read(proc->stdout, test, 9), 9);
    cr_assert_str_eq(test, "     1\tt1");
}

T(spawn_os_read_stdout)
{
	int		in_pipe[2];
	int		out_pipe[2];
	int     child_std_env[2];
	char	*s;
	char	result[7];
	int		pid;

	(void) pipe(in_pipe);
	(void) pipe(out_pipe);
	child_std_env[1] = in_pipe[1];
	child_std_env[0] = out_pipe[0];
	s = "echo hello";
	pid = ft_spawn_cmd(s, __environ, (int *) child_std_env);
	cr_assert_gt(pid, 0, "no alive process was spawned");
	// waitpid(pid, &res, 0);
	// cr_assert_eq(1, 2, "read endless loops here, fix me pls" );
	int read_res = read(child_std_env[0], &result, 5);
	cr_assert_eq(read_res, 5, "read returned %d", read_res);
	printf("returned from read\n");
	cr_assert_str_eq(result, s);
	close(in_pipe[0]);
	close(in_pipe[1]);
	close(out_pipe[0]);
	close(out_pipe[1]);
}
