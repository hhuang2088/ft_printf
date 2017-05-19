/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:35:06 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/15 01:09:25 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(const char *fmt)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (fmt[i] && !is_type(fmt[i]) &&!(fmt[i] >= '1' && fmt[i] <= '9'))
		i++;
	if(fmt[i] >= '1' && fmt[i] <= '9')
		ret += ft_atoi(fmt + i);
	return(ret);
}
