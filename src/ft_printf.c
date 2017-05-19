/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:32:09 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/18 00:48:29 by hehuang          ###   ########.fr       */
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

static int	engine(const char *fmt, va_list *lst, int len, int cnt)
{
	char	*ret;
	void	*arg;
	int		i;

	arg = NULL;
	i = 0;
	if (fmt[i] == '%')
	{
		if (!is_percent(fmt, i))
		{
			arg = va_arg(*lst, void*);
		}
		len += process_tag(fmt, arg);
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
		len = engine(ret, lst, len, cnt);
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list			lst;
	int				cnt;
	int				len;

	va_start(lst, format);
	cnt = count_handle(format);
	len = engine(format, &lst, 0, cnt);
	va_end(lst);
	return (len);
}
