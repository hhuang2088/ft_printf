/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:01 by hehuang           #+#    #+#             */
/*   Updated: 2017/04/26 00:53:09 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int		is_flag(const char flag)
{
  int	i;
  char	*flags;

  i = 0;
  flags = "-0+# ";
  while(flags[i])
  {
	if (flag == flags[i])
	  return(1);
	i++;
  }
  return(0);
}
/*
int main(void)
{
	char	*types;
	int		i;

	types = "sSpdDioOuUxXcC\0";
	i = 0;
	printf("This should equal 1: %d\n", is_flag('0'));
	printf("This should equal 1: %d\n", is_flag('-'));
	printf("This should equal 1: %d\n", is_flag('+'));
	printf("This should equal 1: %d\n", is_flag('#'));
	printf("This should equal 1: %d\n", is_flag(' '));
	while(types[i])
	{
		printf("With this char \'%c\', we should get 0: %d\n", types[i], is_flag(types[i]));
		i++;
	}
	return(0);
}
*/
