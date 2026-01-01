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
	char *arr[] = { NULL};
	cr_assert_eq(ft_arr_len(arr), 0);
}


T(arr_len_1)
{
	char *s = "joa";
	char *arr[] = {s, NULL};
	cr_assert_eq(ft_arr_len(arr), 1);
}
