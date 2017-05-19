/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:12:57 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/17 18:38:17 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *join_width(char *base, char *width, int l_just)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;

	if (l_just)
		ret = ft_strjoin(base, width);
	else
		ret = ft_strjoin(width, base);
	tmp = ft_strdup(base);
	tmp2 = ft_strdup(width);
	free(tmp);
	free(tmp2);
	return (ret);
}
