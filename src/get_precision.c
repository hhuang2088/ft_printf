/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:48 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/19 05:05:14 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_precision(const char *fmt)
{
	int		i;

	i = 0;
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && fmt[i] != '.' && !is_type(fmt[i]))
		i++;
	if (fmt[i] == '.' && fmt[i + 1] >= '1'	&& fmt[i + 1] <= '9')
		return(ft_atoi(fmt + i + 1));
	return(0);
}
