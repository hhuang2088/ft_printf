/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:58:08 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/20 06:42:56 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

is_length(char c)
{
	int		i;
	char	*lengths;

	lengths = "hljz";
	i = 0;
	while (lengths[i])
	{
		if (c == lengths[i])
			return (1);
		i++;
	}
	return (0);
}
