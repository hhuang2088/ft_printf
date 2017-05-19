int		foo(int i, int j)
{
	int	k, l;

	k = 7;
	l = 8;
	return(i + j + k + l);
}

int		main(void)
{
	int i, j;

	i = 5;
	j = 6;
	foo(i, j);
	return(0);
}
