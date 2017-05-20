/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:48:16 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/20 03:24:24 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_hex(const t_tag *tag)
{
	char	*ret;
	char	*num;
	char	*head;
	char	*width;

	if (tag->header || tag->hash)
	{
		if (tag->cap)
			head = "0X";
		else
			head = "0x";
	}
	else
		head = NULL;
	num = precision_itoa(tag, 16, tag->cap);
	if(head)
		ret = ft_strjoin(head, num);
	else
		ret = num;
	width = create_width(tag, ft_strlen(ret));
	if(width)
	{
		if(tag->l_just)
			ret = ft_strjoin(ret, width);
		else
			ret = ft_strjoin(width, ret);
	}
	ft_putstr(ret);
	return(ft_strlen(ret));
}
