/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:24:31 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:25:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		next_spot(const char *fmt, int i)
{
	if (fmt[i])
		i++;
	while (is_flag(fmt[i]))
		i++;
	while (is_digit(fmt[i]))
		i++;
	while (fmt[i] == '.')
		i++;
	while (is_digit(fmt[i]))
		i++;
	while (is_type(fmt[i]))
		i++;
	return (i);
}
