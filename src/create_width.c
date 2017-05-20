/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:51:28 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/20 02:55:06 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_width(const t_tag *tag, int init_len)
{
	char	*ret;
	int		size;
	int		i;
	int		num;

	i = 0;
	size = tag->min_width - init_len;
	ret = ft_strnew(size);
	num = 0;
	if (tag->type == 'd' || tag->type == 'D' || tag->type == 'i')
		num = 1;
	if (num && !tag->l_just)
	{
		if (tag->pad == '0' && !tag->precision)
		{
			if ((int)tag->arg < 0)
				ret[i++] = '-';
			else if ((int)tag->arg > 0 && tag->sign)
				ret[i++] = '+';
		}
	}
	while (i < size - 1)
		ret[i++] = tag->pad;
	if (num && !tag->l_just && tag->sign && !tag->precision)
	{
		if (tag->pad != '0')
		{
			if ((int)tag->arg < 0)
				ret[i] = '-';
			else if ((int)tag->arg > 0)
				ret[i] = '+';
		}
		else
			ret[i] = tag->pad;
	}
	else if (ret)
		ret[i] = tag->pad;
	if (ret)
		return (ret);
	return (NULL);
}
