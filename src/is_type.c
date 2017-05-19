/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:06:24 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/18 00:52:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

int is_type(char c)
{
  int   i;
  char  *types;

  types = "%sSpdDioOuUxXcC\0";
  i = 0;
  while (types[i])
  {
    if (c == types[i])
      return(1);
    i++;
  }
  return(0);
}
