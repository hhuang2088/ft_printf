/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procrustean_bed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 06:59:11 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/29 19:09:16 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_tag	*bed_helper(t_tag *tag)
{
	if (tag->length == 'h')
		tag->arg_ushort = (unsigned short)tag->arg;
	else if (tag->length == 'l')
		tag->arg_ulong = (unsigned long)tag->arg;
	else if (tag->length == 'v')
		tag->arg_ull = (unsigned long long)tag->arg;
	else if (tag->length == 'z')
		tag->arg_sizet = (size_t)tag->arg;
	else if (tag->length == 'H')
		tag->arg_uchar = (unsigned char)tag->arg;
	else if (tag->length == 'j')
		tag->arg_uintmaxt = (uintmax_t)tag->arg;
	return (tag);
}

t_tag		*procrustean_bed(t_tag *tag)
{
	if (tag->length && tag->length != '0')
	{
		if (tag->type == 'i' || tag->type == 'd')
		{
			if (tag->length == 'h')
				tag->arg_short = (short)tag->arg;
			else if (tag->length == 'l')
				tag->arg_long = (long)tag->arg;
			else if (tag->length == 'v')
				tag->arg_ll = (long long)tag->arg;
			else if (tag->length == 'z')
				tag->arg_sizet = (size_t)tag->arg;
			else if (tag->length == 'H')
				tag->arg_char = (signed char)tag->arg;
			else if (tag->length == 'j')
				tag->arg_intmaxt = (intmax_t)tag->arg;
		}
		else if (tag->length && (tag->type == 'o' || tag->type == 'x' ||\
				tag->type == 'X' || tag->type == 'u'))
			bed_helper(tag);
	}
	return (tag);
}
