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
