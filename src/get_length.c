/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:58:08 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:00:22 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_length(const char *fmt)
{
	int		i;

	i = 1;
	while (fmt[i] && !is_type(fmt[i]) && !is_length(fmt[i]))
		i++;
	if (is_length(fmt[i]))
	{
		if (fmt[i] == 'l')
		{
			if (fmt[i + 1] && fmt[i + 1] == 'l')
				return ('v');
			else
				return (fmt[i]);
		}
	}
	else if (fmt[i] == 'h')
	{
		printf("we have a short value\n");
		if (fmt[i + 1] && fmt[i + 1] == 'h')
			return ('H');
		else
			return (fmt[i]);
	}
	return ('0');
}
