/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_kv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:12:15 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/08 14:26:56 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_arr_t.h"
#include <criterion/criterion.h>
#include <libft_kv.h>
#include <libft_arr.h>
#include <libft_str.h>
#include <libft_io.h>

#define T(a) Test(libft_kv, a)

int str_key_cmp(t_kv_key k1, t_kv_key k2)
{
	return ft_strncmp((const char *)k1, (const char *) k2, 10);
}

T(init_put_get)
{
	char *key = "key";
	char *val = "42";
	t_kv *store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key, val);
	cr_assert_eq(ft_kv_get(store, key), val);
	ft_kv_free(store);
}

T(put_overwrites)
{
	char *key = "key";
	char *val1 = "42";
	char *val2 = "34";
	t_kv *store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key, val1);
	ft_kv_put(store, key, val2);
	cr_assert_eq(ft_kv_get(store, key), val2);
	ft_kv_free(store);
}

T(put_overwrites_delete_once)
{
	char *key = "key";
	char *val1 = "42";
	char *val2 = "34";
	t_kv *store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key, val1);
	ft_kv_put(store, key, val2);
	cr_assert_eq(ft_kv_get(store, key), val2);
    t_kv_value poped = ft_kv_pop(store, key);
	cr_assert_eq(poped, val2);
	cr_assert_null(ft_kv_get(store, key));
	ft_kv_free(store);
}

T(two_keys)
{
	char *key1 = "key34";
	char *key2 = "key2";
	char *val1 = "42";
	char *val2 = "34";
	t_kv *store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key1, val1);
	ft_kv_put(store, key2, val2);
	cr_assert_eq(ft_kv_get(store, key1), val1);
	cr_assert_eq(ft_kv_get(store, key2), val2);
	ft_kv_free(store);
}

T(key_not_found)
{
	char *key1 = "key34";
	char *key2 = "key2";
	char *val1 = "42";
	t_kv *store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key1, val1);
	cr_assert_null(ft_kv_get(store, key2));
	ft_kv_free(store);
}

T(list_keys)
{
	char *key1 = "key34";
	char *key2 = "key2";
	char *val1 = "42";
	char *val2 = "34";
	t_kv *store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key1, val1);
	ft_kv_put(store, key2, val2);
	char **act_keys = (char **) ft_kv_keys(store);
	cr_assert_eq(ft_arr_len((t_arr) act_keys), 2, "len is  %d", (int) ft_arr_len((t_arr) act_keys));
    char *exp_keys[] ={ key1, key2, NULL } ;

	size_t i = 0;
	while (exp_keys[i] || act_keys[i])
	{
        cr_assert_eq(act_keys[i], exp_keys[i]);
		i++;
	}
	ft_kv_free(store);
}

