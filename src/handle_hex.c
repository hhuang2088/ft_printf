/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:07:25 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:33:10 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_hex_helper(char *ret, char *width, int l_just)
{
	if (l_just)
		return (ft_strjoin(ret, width));
	return (ft_strjoin(width, ret));
}

int			handle_hex(const t_tag *tag)
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
	num = precision_utoa(tag, 16, tag->cap);
	if (head)
		ret = ft_strjoin(head, num);
	else
		ret = num;
	width = create_width(tag, ft_strlen(ret));
	if (width)
		ret = handle_hex_helper(ret, width, tag->l_just);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
