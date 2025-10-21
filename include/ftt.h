/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:57:31 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/06 23:00:54 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FTT_LIB_H
#define FTT_LIB_H
#include <stdlib.h>
#include <libft.h>

void *ftt_malloc(size_t s);

size_t ftt_array_lenth(const t_byte **start, const size_t el_s);

#endif
