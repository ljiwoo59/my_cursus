extern int	g_flagarr;

void	makewatch(int *dst, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (i % 2 == 0)
		{
			if (src[i] >= '1' && src[i] <= '4')
			{
				dst[j] = src[i] - '0';
				j++;
			}
			else
				return ;
		}
		else
		{
			if (src[i] != ' ')
				return ;
		}
		i++;
	}
	g_flagarr = 1;
}
