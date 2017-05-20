/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:33 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/20 02:53:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int          process_tag(const char *fmt, void *c)
{
	int		j;
	t_tag	*tag;
	char	*flags;
	int		len;

	j = 0;
	tag = init_tag(fmt, c);
	tag->type = get_type(fmt);
	flags = scan_flag(fmt);
	if (flags[0] == '-')
		tag->l_just = 1;
	if (flags[1] == '0' && tag->type != 'c' && tag->type != 's' && !tag->l_just && !tag->precision)
		tag->pad = '0';
	if (flags[2] == '+')
		tag->sign = 1;
	if (flags[3] == '#')
		tag->hash = 1;
	if (flags[4] == ' ')
			tag->space = 1;
	if((tag->type == 'd' || tag->type == 'D' || tag->type == 'i') && \
			(int)tag->arg < 0)
		tag->neg = 1;
	len = handle_tag(tag);
	return(len);
}
