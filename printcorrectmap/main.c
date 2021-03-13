#include <unistd.h>

int		g_watch[16] = {0, };
int		g_flagarr = 0;
void	makewatch(int *dst, char *src);
void	rush();

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
	}
	else
	{
		makewatch(g_watch, argv[1]);
		if (g_flagarr == 1)
			rush();
		else
		{
			write(1, "Error", 5);
			write(1, "\n", 1);
		}
	}
	return (0);
}
