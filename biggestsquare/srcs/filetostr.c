#include "ft_h.h"

extern char *g_file;

void	filetostr(char *str)
{
	int		fd;
	int		byte;
	char	c;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
	}
	else
	{
		byte = 0;
		while (read(fd, &c, 1) > 0)
			byte++;
		close(fd);
		g_file = (char *)malloc(byte + 1);
		fd = open(str, O_RDONLY);
		read(fd, g_file, byte);
		g_file[byte] = 0;
		close(fd);
	}
}
