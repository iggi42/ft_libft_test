/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:48:49 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/09 21:54:20 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ftt.h"
#include "libft_mem.h"
#include "libft_str.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void *ftt_malloc(size_t s)
{
	size_t	i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *) malloc(s);
	while (i < s)
	{
		*(result + i) = (char) i;
		i++;
	}
	return (result);
}

bool is_zero(const void *start, const size_t size)
{
	if (size == 0)
		return true;
	t_byte rele = * (t_byte *) start;
	if (rele != 0)
		return false;
	return is_zero(start + 1, size - 1);
}

void ftt_array_free(const void **start)
{
	void **current;

	current = (void **) start;
	while(*current)
		free(*(current++));
	free(start);
}

size_t ftt_array_lenth(const void *start, const size_t el_s)
{
	size_t l;

	l = 0;
	while (!is_zero(start, el_s))
	{
		start += el_s;
		l++;
	}
	return (l);
}

void ftt_assert_io_stdout(const char* expected_str)
{
	FILE *stdout = cr_get_redirected_stdout();
	size_t size = ft_strlen(expected_str);
	char *red = ft_str_alloc(size);
	size_t fread_res = fread(red,  sizeof(char), size, stdout);
	if (fread_res != size)
		printf("fread return val is fucked\n");
	// cr_assert_eq(fread_res, size, "fread returned %d, we hoped for %d", (int) fread_res, (int) size);
	cr_assert_str_eq(red, expected_str, "expected: \"%s\" but stdout had \"%s\"\n", red, expected_str);
}

void ftt_switch(int *a, int *b)
{
	int buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

// int ftt_str2fd(const char *s)
// {
// 	int		pipe_fds[2];
// 	int		fork_res;
// 	char	*result;

// 	fork_res = fork();
// 	if (fork_res)
// 	{ // parent part
// 		ft_putstr_fd(s, pipe_fds[1]);
// 	}
// 	else
// 	{
// 		// child part
// 		// waitpid(fork_res, child_res, 10);
// 		result = ft_gnl(pipe_fds[0]);
// 		cr_assert_str_eq(result, s);
// 	}
// 	close(pipe_fds[0]);
// 	close(pipe_fds[1]);
// }

