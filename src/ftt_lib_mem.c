/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:23:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/09 21:58:15 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftt.h"
#include <criterion/alloc.h>
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <libft.h>
#include <string.h>

Test(libft_mem, bzero_simple)
{
	int *target = ftt_malloc(42 * sizeof(int));
	ft_bzero(target, 42 * sizeof(int));

	size_t i;
	for (i = 0; i < 42; i++) {
	  cr_assert_eq(*(target + i), 0, "not '0' at index %d, but %x", (int) i, *(target + i));
	}
	free(target);
}

Test(libft_mem, bzero_empty)
{
	int *arr = (int *) ftt_malloc(0 * sizeof(int));
	ft_bzero(arr, 0);
	free(arr);
}

Test(libft_mem, memset_simple)
{
	size_t size = 20;
	int val = 2;
	int *target = (int *) ftt_malloc(size * sizeof(int));

	ft_memset(target, val, size * sizeof(int));

	size_t i;
	for (i = 0; i < size; i++)
	{
		unsigned char el = *(target + i);
		
	  cr_assert_eq(el, val, "not %d, but %d at index %d", val, el, (int) i);
	}
	free(target);
}

Test(libft_mem, memset_system_cmp)
{
	size_t size = 20;
	int val = 2;
	int *a_ft = (int *) ftt_malloc(size * sizeof(int));
	int *a_s = (int *) ftt_malloc(size * sizeof(int));

	ft_memset(a_ft, val, size * sizeof(int));
	ft_memset(a_s, val, size * sizeof(int));

	cr_assert_eq(memcmp(a_ft, a_s, size), 0);
	free(a_ft);
	free(a_s);
}

Test(libft_mem, memset_empty)
{
	int *target = (int *) ftt_malloc(0 * sizeof(int));
	ft_memset(target, (int) 'S', 0);
	free(target);
}

Test(libft_mem, calloc_simple)
{
	int *target = (int *) ft_calloc(42, sizeof(int));

	size_t i;
	for (i = 0; i < 42; i++)
	  cr_assert_eq(*(target + i), 0, "not '0' at index %d", (int) i);
	free(target);
}

Test(libft_mem, calloc_empty)
{
	int *target = (int *) ft_calloc(0, sizeof(int));

	free(target);
}

Test(libft_mem, calloc_empty2)
{
	int *target = (int *) ft_calloc(1, 0);

	free(target);
}

Test(libft_mem, memcmp_eq)
{
	int a1[] = {1, 2, 3};
	int a2[] = {1, 2, 3};
  int result = ft_memcmp(a1, a2, 3);
	cr_assert_eq(result, 0, "0 should be equal, but is %d", result);
}

Test(libft_mem, memcmp_lower)
{
	char a1[] = {1, 2, 3, 4};
	char a2[] = {1, 2, 100, 4};
  int result = ft_memcmp(a1, a2, 4 * sizeof(char));
  cr_assert_lt(result, 0, "result be negative, but is '%d'", result);
}

Test(libft_mem, memcmp_higher)
{
	char a1[] = {1, 2, 3, 4};
	char a2[] = {1, 2, 1, 4};
  int result = ft_memcmp(a1, a2, 4 * sizeof(char));
  cr_assert_gt(result, 0, "result be positive, but is '%d'", result);
}

Test(libft_mem, memchr_easy)
{
	char a[] = {'a', 'b', 'c'};
	void *result = ft_memchr(a, 'a', 3);
	cr_assert_eq(a, result);
}

Test(libft_mem, memmove_easy)
{
	// TODO
}
