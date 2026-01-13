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
#include <libft_str.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "../include/ftt.h"

#define T(a) Test(libft_io, a)

#define ftt_printf(expected, template, ...) { \
	int expected_len = (int) ft_strlen(expected); \
	int result = ft_printf(template, __VA_ARGS__); \
    cr_assert_eq(result, expected_len, "printf return: %d, strlen of expected: %d \"%s\"\n", result, expected_len, expected); \
    ftt_assert_io_stdout(expected); \
}

T(printf_test)
{
	cr_redirect_stdout();
	ftt_printf("Test (nil)\n", "Test %p\n", NULL);
	ftt_printf("Test (null)\n", "Test %s\n", NULL);
	ftt_printf("joas c joa\n", "joas %c joa\n", 'c');
	ftt_printf("joas servus joa\n", "joas %s joa\n", "servus");
	ftt_printf("answer: 42\n", "answer: %i\n", 42);
	ftt_printf("lower hex: deadbeef\n", "lower hex: %x\n", 0xdeadbeef);
	ftt_printf("upper hex: BAD1DEA\n", "upper hex: %X\n", 0xbad1dea);
	ftt_printf("just a %\n", "just a %%\n", NULL);
}

T(gnl_end_with_nl)
{
	int		pipe_fds[2];
	int		fork_res;
	char	*result;

	fork_res = fork();
	if (fork_res)
	{ // parent part
		ft_putstr_fd("joa, oida\n", pipe_fds[1]);
	}
	else
	{ // child part
		// waitpid(fork_res, child_res, 10);
		result = ft_gnl(pipe_fds[0]);
		cr_assert_str_eq(result, "joa, oida\n");
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}	
