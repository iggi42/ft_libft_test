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


size_t ftt_array_lenth(const void *start, const size_t el_s)
{
	size_t l;
  t_byte *s = (t_byte *) start;

	l = 0;
	while (*(s + el_s * l) != 0) l++;
	return (l);
}
