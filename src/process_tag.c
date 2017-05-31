/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:33 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:56:09 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tag	*flag_helper(t_tag *tag, char *flags)
{
	if (flags[0] == '-')
		tag->l_just = 1;
	if (flags[1] == '0' && tag->type != 'c' && tag->type != 's' &&\
			!tag->l_just && !tag->precision)
		tag->pad = '0';
	if (flags[2] == '+')
		tag->sign = 1;
	if (flags[3] == '#')
		tag->hash = 1;
	if (flags[4] == ' ')
		tag->space = 1;
	if ((tag->type == 'd' || tag->type == 'D' || tag->type == 'i') && \
			(int)tag->arg < 0)
		tag->neg = 1;
	return (tag);
}

int		process_tag(const char *fmt)
{
	t_tag	*tag;
	char	*flags;
	int		len;

	tag = init_tag(fmt);
	tag->type = get_type(fmt);
	flags = scan_flag(fmt);
	tag = flag_helper(tag, flags);
	tag->length = get_length(fmt);
	tag = procrustean_bed(tag);
	len = handle_tag(tag);
	return (len);
}
