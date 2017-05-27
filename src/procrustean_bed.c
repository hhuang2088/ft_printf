/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procrustean_bed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 06:59:11 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/26 14:27:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"

static void	*bed_helper(const arg, const length)
{
	if (length == 'h')
		return ((void*)((unsigned short)arg));
	else if (length == 'l')
		return ((void*)(unsigned long)arg);
	else if (length == 'v')
		return ((void*)(unsigned long long)arg);
	else if (length == 'z')
		return ((void*)((size_t)arg));
	else if (length == 'H')
		return ((void*)((unsigned char)arg));
	else if (length == 'j')
		return ((void*)((uintmax_t)arg));
	return (arg);
}

void		*procrustean_bed(const arg, const length, const type)
{
	if (length && (type == 'i' || type == 'd'))
	{
		if (length == 'h')
			return ((void*)((short)arg));
		else if (length == 'l')
			return ((void*)((long)arg));
		else if (length == 'v')
			return ((void*)((long long)arg));
		else if (length == 'z')
			return ((void*)((size_t)arg));
		else if (length == 'H')
			return ((void*)((signed char)arg));
		else if (length == 'j')
			return ((void*)((intmax_t)arg));
	}
	else if (length && (type == 'o' || type == 'x' ||\
				type == 'X' || type == 'u' ||))
		bed_helper(arg, length);
	else
		return (arg);
}
