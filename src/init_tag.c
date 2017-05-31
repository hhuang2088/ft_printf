/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:48:30 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/26 03:43:19 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tag	*init_tag(const char *fmt)
{
	t_tag	*ret;
	int		i;

	if (!(ret = (t_tag*)malloc(sizeof(t_tag))))
		return (NULL);
	i = 0;
	ret->type = get_type(fmt);
	ret->min_width = get_width(fmt);
	ret->precision = get_precision(fmt);
	ret->length = get_length(fmt);
	printf("length is at: %c\n", ret->length);
	ret->cap = 0;
	ret->hash = 0;
	ret->header = 0;
	ret->l_just = 0;
	ret->pad = ' ';
	ret->sign = 0;
	ret->neg = 0;
	ret->arg = va_arg(g_lst, void*);
	ret->arg_short = 0;
	ret->arg_long = 0;
	ret->arg_ll = 0;
	ret->arg_ushort = 0;
	ret->arg_ulong = 0;
	ret->arg_ull = 0;
	ret->arg_sizet = 0;
	ret->arg_char = 0;
	ret->arg_uchar = 0;
	ret->arg_intmaxt = 0;
	ret->arg_uintmaxt = 0;
	return(ret);
}
