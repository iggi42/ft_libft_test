/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:12:15 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/08 14:26:56 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <criterion/criterion.h>
#include <libft_arr.h>
#include <libft_io.h>

#define T(a) Test(libft_arr, a)

T(arr_len_0)
{
	char *arr[] = { NULL };
	cr_assert_eq(ft_arr_len(arr), 0);
}

T(arr_len_1)
{
	char *s = "joa";
	char *arr[] = {s, NULL};
	cr_assert_eq(ft_arr_len(arr), 1);
}

T(arr_len_3)
{
	char *s = "joa";
	char *arr[] = {s, s, s, NULL};
	cr_assert_eq(ft_arr_len(arr), 3);
}

static void quad(void *p)
{
	int *i = p;
	*i = *i + *i;
}

T(arr_each)
{
	int i[] = {7, 4, 3 };
	int *arr[] = {&i[0], &i[1], &i[2], NULL};
	ft_arr_each(arr, quad);
	cr_assert_eq(i[0], 14);
	cr_assert_eq(i[1], 8);
	cr_assert_eq(i[2], 6);
}

static void *add(void *acc, void *el)
{
	*(int *) acc += *(int *) el;
	return acc;
}

T(arr_fold_sum)
{
	int els[] = {7, 4, 3 };
	int sum = 0;
	int *arr[] = {&els[0], &els[1], &els[2], NULL};

	cr_assert_eq(&sum, ft_arr_fold(arr, add, &sum));
	cr_assert_eq(sum, 14);
}

static void *bigger(void *acc, void *el)
{
	if (*(int *) acc > *(int*) el)
		return acc;
	return el;
}

T(arr_fold_chose_acc)
{
	int els[] = {7, 4, 3, 103 };
	int biggest = 0;
	int *arr[] = {&els[0], &els[1], &els[2], &els[3], NULL};

	cr_assert_eq(&els[3], ft_arr_fold(arr, bigger, &biggest));
}

