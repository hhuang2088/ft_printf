/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:25:55 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:12:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_oct(const t_tag *tag)
{
	char	*ret;
	char	*width;

	ret = precision_utoa(tag, 8, 0);
	if (tag->hash && !tag->precision)
		ret = ft_strjoin("0", ret);
	width = create_width(tag, ft_strlen(ret));
	if (width)
	{
		if (tag->l_just)
			ret = ft_strjoin(ret, width);
		else
			ret = ft_strjoin(width, ret);
	}
	ft_putstr(ret);
	return (ft_strlen(ret));
}
