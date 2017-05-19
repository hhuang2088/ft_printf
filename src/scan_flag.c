/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 23:39:54 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/18 00:00:06 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*scan_flag(const char *fmt)
{
	int		i;
	char	*flags;

	i = 0;
	flags = (char*)malloc(sizeof(char) * 6);
	while (i < 5)
		flags[i++] = '@';
	flags[i] = '\0';
	i = 1;
	while (fmt[i] && !is_type(fmt[i]) && is_flag(fmt[i]))
	{
		if (fmt[i] == '-' && flags[0] == '@')
			flags[0] = '-';
		if (fmt[i] == '0' && flags[1] == '@')
			flags[1] = '0';
		if (fmt[i] == '+' && flags[2] == '@')
			flags[2] = '+';
		if (fmt[i] == '#' && flags[3] == '@')
			flags[3] = '#';
		if (fmt[i] == ' ' && flags[4] == '@')
			flags[4] = ' ';
		i++;
	}
	return (flags);
}
