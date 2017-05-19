/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:53:03 by hehuang           #+#    #+#             */
/*   Updated: 2017/04/28 11:56:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_length(char c)
{
	char	mods[6];
	int		i;

	mods = "hljz";
	i = 0;
	while (mods[i])
	{
		if(c == mods[i])
			return(1);
		i++;
	}
	return(0)
}

int		main(void)
{
	char	*mod;

	mod = "hljz";
	while()
	return(0);
}