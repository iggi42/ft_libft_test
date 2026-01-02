/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_lib_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:12:15 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/08 14:26:56 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <criterion/criterion.h>
#include <libft_ll.h>

#define T(a) Test(libft_lst, a)

T(pop_empty)
{
	t_list	*empty;

	empty = NULL;
	cr_assert_null(ft_lst_pop(&empty));
}

T(pop_1)
{
	int		i;
	t_list	*lst;

	lst = ft_lstnew(&i);
	cr_assert_eq(&i, ft_lst_pop(&lst));
	cr_assert_null(ft_lst_pop(&lst));
	cr_assert_null(ft_lst_pop(&lst));
}

T(pop_2)
{
	int		i;
	int		a;
	t_list	*lst;

	lst = ft_lstnew(&i);
	ft_lstadd_front(&lst, ft_lstnew(&a));
	cr_assert_eq(&a, ft_lst_pop(&lst));
	cr_assert_eq(&i, ft_lst_pop(&lst));
	cr_assert_null(ft_lst_pop(&lst));
	cr_assert_null(ft_lst_pop(&lst));
	cr_assert_null(ft_lst_pop(&lst));
}
