/**************************************************************************   */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_iol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <your@mail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:25:34 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 15:29:23 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftt.h"
#include "libft.h"
#include <criterion/criterion.h>

#define T(a) Test(libft_iol, a)

T(ft_iol_size)
{
	t_list	*list;

	list = NULL;
	cr_assert_eq(ft_iol_size(list), 0);
}

T(ft_iol_size_1)
{
	char		b[100];
	t_iol_el	el1;
	t_list		l1;
	t_list		*list;
	size_t		result;

	el1.buffer = (char *)&b;
	el1.size = 10;
	l1.content = &el1;
	l1.next = NULL;
	list = &l1;
	result = ft_iol_size(list);
	cr_assert_eq(result, 10, "ne ist %d", (int)result);
}

T(ft_iol_str_null)
{
	t_list	*list;
	char *s;

	list = NULL;
	cr_assert_str_eq(s = ft_iol_str(list), "");
	free(s);
}

T(ft_iol_str_0)
{
	t_iol_el	empty;
	t_list		l1;
	char *s;

	l1.content = &empty;
	l1.next = NULL;
	empty.buffer = NULL;
	empty.size = 0;
	cr_assert_str_eq(s = ft_iol_str(&l1), "");
	free(s);
}

T(ft_iol_str_3)
{
	char	b[100];
	size_t	actual_size;
	char	*result;
	char	b2[100];
	t_iol_el eins, eins_zwei, aca;
	t_list post, middle, pre;

	ft_bzero(&b, 100);
	ft_bzero(&b2, 100);

	b[0] = '1';
	b[1] = '2';
	b[10] = 'A';
	b[11] = 'c';
	b[12] = 'A';

	eins.size = 1;
	eins.buffer = ((char *)b);
	eins_zwei.size = 2;
	eins_zwei.buffer = ((char *)b);
	aca.size = 3;
	aca.buffer = (char *)b + 10;
	post.content = &eins_zwei;
	post.next = NULL;
	middle.content = &aca;
	middle.next = &post;
	pre.content = &eins;
	pre.next = &middle;
	actual_size = 6;

	result = ft_iol_str(&pre);
	cr_assert_eq(ft_iol_str_l(&pre, (char *)&b2, 100), actual_size);
	cr_assert_str_eq((char *)&b2, "1AcA12");
	cr_assert_str_eq(result, "1AcA12");
	free(result);
}

T(ft_iol_append)
{
	t_list	*list;
	char *s;

	list = NULL;
	ft_iol_append(&list, "-[", 2);
	ft_iol_append(&list, "joa", 3);
	ft_iol_append(&list, "]-", 2);
	cr_assert_str_eq(s = ft_iol_str(list), "-[joa]-");
	free(s);
	ft_iol_del(&list);
}
