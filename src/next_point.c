/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 05:58:42 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/18 00:26:59 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   next_point(const char *fmt, int i)
{
	if (fmt[i] && fmt[i] == '%')
		i++;
	while(fmt[i])
	{
		if(is_type(fmt[i]))
		{
			i++;
			return(i);
		}
		i++;
	}
  return(i);
}