#include <unistd.h>
#define SIZE 4

extern int	g_watch[16];
int			g_flag = 0;
int			g_k;
int			g_check;
int			g_buf[SIZE][SIZE];

int		checking(int arr[SIZE][SIZE]);

void	ft_strcpy(int dst[SIZE][SIZE], int src[SIZE][SIZE])
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void	print_arr(int arr[SIZE][SIZE])
{
	int		col;
	int		row;
	char	num;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			num = arr[row][col] + '0';
			write(1, &num, 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		islast(int arr[SIZE][SIZE], int index)
{
	if (index == 16)
	{
		if (checking(arr) == 1)
		{
			g_flag = 1;
			print_arr(arr);
			return (1);
		}
		else
			return (1);
	}
	return (0);
}

void	nextbox(int arr[SIZE][SIZE], int index)
{
	int i;
	int j;

	if (islast(arr, index))
		return ;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		g_k = 0;
		g_check = 1;
		while (++j < index / 4 || g_k < index % 4)
		{
			if (i + 1 == arr[j][index % 4] || i + 1 == arr[index / 4][g_k])
				g_check = 0;
			g_k++;
		}
		if (g_check)
		{
			g_buf[index / 4][index % 4] = i + 1;
			nextbox(g_buf, index + 1);
			g_buf[index / 4][index % 4] = 0;
		}
	}
}

void	rush(void)
{
	int arr[SIZE][SIZE];
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	nextbox(arr, 0);
	if (g_flag == 0)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
	}
}
