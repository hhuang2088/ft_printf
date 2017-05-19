/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:39:14 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/17 22:03:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_handle(const char *fmt)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			if (!is_percent(fmt, i))
				cnt++;
			if (fmt[i + 1])
				i++;
		}
		i++;
	}
	return (cnt);
}
