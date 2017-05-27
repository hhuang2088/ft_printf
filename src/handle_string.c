/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:43:33 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:13:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_string(const t_tag *tag)
{
	int		raw_len;
	char	*width;

	raw_len = ft_strlen((char*)tag->arg);
	width = create_width(tag, raw_len);
	if (width)
	{
		if (tag->l_just)
		{
			ft_putstr((char*)tag->arg);
			ft_putstr(width);
		}
		else
		{
			ft_putstr(width);
			ft_putstr((char*)tag->arg);
		}
		return (raw_len + ft_strlen(width));
	}
	ft_putstr((char*)tag->arg);
	return (raw_len);
}
