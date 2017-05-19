/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:48:30 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/16 21:21:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int is_type(char c)
{
  int   i;
  char  *types;

  types = "sSpdDioOuUxXcC\0";
  i = 0;
  while(types[i])
  {
    if(c == types[i])
      return(1);
    i++;
  }
  return(0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char        get_type(const char *tag)
{
  int	len;
  char	type;

  len = ft_strlen((char*)tag);
  type = tag[len-1];
  if(is_type(type))
    return(type);
  return(0);
}

typedef struct			s_tag
{
	char		*flags;
	int         min_width;
	int         max_width;
	int         precision;
	char        type;
	void		*arg;
}						t_tag;
*/
t_tag	*init_tag(const char *fmt, void *c)
{
	t_tag	*ret;
	int		i;

	if (!(ret = (t_tag*)malloc(sizeof(t_tag))))
		return (NULL);
	i = 0;
	ret->arg = c;
	ret->type = get_type(fmt);
	ret->min_width = get_width(fmt);
	ret->cap = 0;
	ret->hash = 0;
	ret->header = 0;
	ret->l_just = 0;
	ret->pad = ' ';
	ret->sign = 0;
	ret->neg = 0;
	return(ret);
}
/*
char		*flags;
int			init_width;
int         min_width;
int         max_width;
int         precision;
char        type;
int			header;
int			hash;
int			cap;
void		*arg;


int		main(void)
{
	t_tag	*tag;

	tag = init_tag("%d", (void*)1234);
	printf("tag has a flag: %s\n", tag->flags);
	printf("tag has a min_width: %d\n". tag->min_width);
	printf("tag has a max_width: %d\n". tag->max_width);
}

*/
