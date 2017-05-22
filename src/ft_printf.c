/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:32:09 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/22 09:32:47 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*next_fmt(const char *fmt, int i)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(fmt);
	ret = ft_strdup(fmt + i);
	free(tmp);
	return (ret);
}

static int	engine(const char *fmt, int len, int cnt)
{
	char	*ret;
	int		i;

	i = 0;
	if (fmt[i] == '%')
	{
		len += process_tag(fmt);
		i = next_point(fmt, i);
		cnt--;
	}
	while (fmt[i] && fmt[i] != '%')
	{
		ft_putchar(fmt[i++]);
		len++;
	}
	if (fmt[i] && fmt[i] == '%')
	{
		ret = next_fmt(fmt, i);
		len = engine(ret, len, cnt);
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	int				cnt;
	int				len;

	va_start(g_lst, format);
	cnt = count_handle(format);
	len = engine(format, 0, cnt);
	va_end(g_lst);
	return (len);
}
