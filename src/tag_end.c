#include "ft_printf"
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
/*
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

int		is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return(1);
	return(0);
}
*/
int		next_spot(const char *fmt, int i)
{
	if(fmt[i])
		i++;
	while(is_flag(fmt[i]))
		i++;
	while(is_digit(fmt[i]))
		i++;
	while(fmt[i] == '.')
		i++;
	while(is_digit(fmt[i]))
		i++;
	while(is_type(fmt[i]))
		i++;
	return(i);
}
/*
int		main(void)
{
	char	*str;
	char	*tmp;
	int		i;

	str = "%-0+# 100000000.1000000dAfter the tag!!";
	printf("str before process: %s\n", str);
	i = next_spot(str, 0);
	tmp = strdup(str);
	str = strdup(tmp + i);
	free(tmp);
	printf("i should equal 24, %d\n", i);
	printf("str after process: %s\n", str);
	free(str);
}
*/
