/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 08:52:37 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/22 09:38:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_pad(int len, int neg, int sign)
{
	char	*prec;
	int		i;
	int		space;

	space = 0;
	if (neg || sign)
		space = 1;
	i = 0;
	if (len <= 0)
		prec = NULL;
	else
	{
		prec = ft_strnew(len + space);
		if (neg)
			prec[i++] = '-';
		else if (sign && !neg)
			prec[i++] = '+';
		while (i < (len + space))
			prec[i++] = '0';
	}
	return (prec);
}

char	*precision_itoa(const t_tag *tag, int base, int cap)
{
	char	*ret;
	char	*prec;
	int		num;
	int		len;
	int		neg;

	num = (int)tag->arg;
	neg = 0;
	if (num < 0 && !tag->l_just)
	{
		num = -num;
		neg = 1;
	}
	ret = ft_itoa_base(num, base, cap);
	len = tag->precision - ft_strlen(ret);
	prec = zero_pad(len, neg, tag->sign);
	if (prec)
		ret = ft_strjoin(prec, ret);
	return (ret);
}
