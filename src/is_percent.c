/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:56:55 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/18 00:48:11 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	is_percent(const char *fmt, int i)
{
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && (!is_type(fmt[i]) || is_flag(fmt[i]) || ft_isdigit(fmt[i])))
		i++;
	if (fmt[i] == '%')
		return (1);
	return (0);
}
/*
int		main(void)
{

	printf("This should return a 1: %d\n", is_percent("%%", 0));
	printf("This should return a 1: %d\n", is_percent("%%%", 1));
	printf("This should return a 0: %d\n", is_percent("%%%", 2));
	printf("This should return a 0: %d\n", is_percent("The quick brown fox jumped over the lazy %s", 41));
	printf("This should return a 1: %d\n", is_percent("The quick brown fox jumped over the lazy %%", 41));
	return(0);
}
*/
