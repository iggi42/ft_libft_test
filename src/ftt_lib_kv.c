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
#include <criterion/criterion.h>
#include <libft_kv.h>
#include <libft_arr.h>

#define T(a) Test(libft_kv, a)

T(init_put_get)
{
	char *key = "key";
	char *val = "42";
	t_kv_store *store = ft_kv_init();
	ft_kv_put(store, key, val);
	cr_assert_eq(ft_kv_get(store, key), val);
	ft_kv_free(store);
}

T(put_overwrites)
{
	char *key = "key";
	char *val1 = "42";
	char *val2 = "34";
	t_kv_store *store = ft_kv_init();
	ft_kv_put(store, key, val1);
	ft_kv_put(store, key, val2);
	cr_assert_eq(ft_kv_get(store, key), val2);
	ft_kv_free(store);
}

T(two_keys)
{
	char *key1 = "key34";
	char *key2 = "key2";
	char *val1 = "42";
	char *val2 = "34";
	t_kv_store *store = ft_kv_init();
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
	t_kv_store *store = ft_kv_init();
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
	t_kv_store *store = ft_kv_init();
	ft_kv_put(store, key1, val1);
	ft_kv_put(store, key2, val2);
	char **act_keys = (char **) ft_kv_keys(store);
	cr_assert_eq(ft_arr_len(act_keys), 2);
    char *exp_keys[] ={ key1, key2, NULL } ;

	size_t i = 0;
	while (exp_keys[i] || act_keys[i])
	{
        cr_assert_eq(act_keys[i], exp_keys[i]);
		i++;
	}
	ft_kv_free(store);
}

