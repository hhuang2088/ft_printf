/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:47:43 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/17 21:58:39 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_char(const t_tag *tag)
{
	char	*width;
	int		len;

	len = 0;
	width = NULL;
	if(tag->min_width > 0)
		width = create_width(tag, 1);
	if(width)
	{
		if(tag->l_just)
		{
			ft_putchar((char)tag->arg);
			ft_putstr(width);
		}
		else
		{
			ft_putstr(width);
			ft_putchar((char)tag->arg);
		}
		len = ft_strlen(width);
		free(width);
		return(1 + len);
	}
	ft_putchar((char)tag->arg);
	return(1);
}
