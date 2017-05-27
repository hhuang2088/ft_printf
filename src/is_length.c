/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:53:03 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:15:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_length(const char length)
{
	char	*mods;
	int		i;

	mods = "hljz\0";
	i = 0;
	while (mods[i])
	{
		if (length == mods[i])
			return (1);
		i++;
	}
	return (0);
}
