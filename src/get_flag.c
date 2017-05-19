/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 04:09:41 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/09 04:10:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flag(char flag)
{
	char	*flags;
	int		i;

	flags = "-0+# ";
	while(i < ft_strlen(flags))
	{
		if (flags[i++] == flag)
			return(flags[i]);
	}
	return(0);
}
