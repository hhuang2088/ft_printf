/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:48:30 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/19 05:05:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tag	*init_tag(const char *fmt, void *c)
{
	t_tag	*ret;
	int		i;

	if (!(ret = (t_tag*)malloc(sizeof(t_tag))))
		return (NULL);
	i = 0;
	ret->arg = c;
	ret->type = get_type(fmt);
	ret->min_width = get_width(fmt);
	ret->precision = get_precision(fmt);
	ret->cap = 0;
	ret->hash = 0;
	ret->header = 0;
	ret->l_just = 0;
	ret->pad = ' ';
	ret->sign = 0;
	ret->neg = 0;
	return(ret);
}
