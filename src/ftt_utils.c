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
#include "libft.h"
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
