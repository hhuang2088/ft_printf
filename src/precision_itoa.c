/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 08:52:37 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/29 19:15:56 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_dec(const t_tag *tag, int base, int cap)
{
	if (tag->length == 'l')
		return(ft_itoa_base(tag->arg_long, base, cap));
	else if (tag->length == 'v')
		return(ft_itoa_base(tag->arg_ll, base, cap));
	else if (tag->length == 'h')
	{
		printf("returning short value\n");
		return(ft_itoa_base(tag->arg_short, base, cap));
	}
	else if (tag->length == 'z')
		return(ft_itoa_base(tag->arg_sizet, base, cap));
	else if (tag->length == 'H')
		return(ft_itoa_base(tag->arg_char, base, cap));
	else if (tag->length == 'j')
		return(ft_itoa_base(tag->arg_intmaxt, base, cap));
	return(ft_itoa_base((int)tag->arg, base, cap));
}

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
	char			*ret;
	char			*prec;
	int				len;
	int				neg;
	long long		arg;

	neg = 0;
	arg = (int)tag->arg;
	if (arg < 0)
	{
		arg = -arg;
		neg = 1;
	}
	ret = get_dec(tag, base, cap);
	len = tag->precision - ft_strlen(ret);
	prec = zero_pad(len, neg, tag->sign);
	if (prec)
		ret = ft_strjoin(prec, ret);
	return (ret);
}
