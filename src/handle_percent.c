/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:42:37 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:12:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_percent(const t_tag *tag)
{
	char	*width;
	int		len;

	len = 0;
	width = NULL;
	if (tag->min_width > 0)
		width = create_width(tag, 1);
	if (width)
	{
		if (tag->l_just)
		{
			ft_putchar('%');
			ft_putstr(width);
		}
		else
		{
			ft_putstr(width);
			ft_putchar('%');
		}
		len = ft_strlen(width);
		free(width);
		return (1 + len);
	}
	ft_putchar('%');
	return (1);
}
