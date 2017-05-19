/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:18 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/18 00:50:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_type(const char *fmt)
{
	char	type;
	int		i;

	i = 0;
	if (fmt[i] == '%')
		i++;
	type = '\0';
	while (!is_type(fmt[i]))
		i++;
	if (fmt[i] && is_type(fmt[i]))
		type = fmt[i];
	return (type);
}
