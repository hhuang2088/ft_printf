/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_utoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:27:54 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:21:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*zero_pad(int len)
{
	char	*prec;
	int		i;

	i = 0;
	if (len <= 0)
		prec = NULL;
	else
	{
		prec = ft_strnew(len);
		while (i < len)
			prec[i++] = '0';
	}
	return (prec);
}

char			*precision_utoa(const t_tag *tag, int base, int cap)
{
	char					*ret;
	char					*prec;
	unsigned long long		num;
	int						len;

	num = (unsigned long long)tag->arg;
	ret = ft_utoa_base(num, base, cap);
	len = tag->precision - ft_strlen(ret);
	prec = zero_pad(len);
	if (prec)
		ret = ft_strjoin(prec, ret);
	return (ret);
}
