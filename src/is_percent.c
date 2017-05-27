/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:56:55 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:15:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_percent(const char *fmt, int i)
{
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && (!is_type(fmt[i]) || is_flag(fmt[i]) ||\
				ft_isdigit(fmt[i])))
		i++;
	if (fmt[i] == '%')
		return (1);
	return (0);
}
