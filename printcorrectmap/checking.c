#define SIZE 4

extern int g_watch[16];

int		colup(int arr[SIZE][SIZE], int count, int row, int col)
{
	int i;
	int max;

	i = 0;
	col = 0;
	while (i < 4)
	{
		count = 0;
		max = 0;
		row = 0;
		while (row < 4)
		{
			if (max < arr[row][col])
			{
				max = arr[row][col];
				count++;
			}
			row++;
		}
		if (count != g_watch[i])
			return (0);
		i++;
		col++;
	}
	return (1);
}

int		coldown(int arr[SIZE][SIZE], int count, int row, int col)
{
	int i;
	int max;

	i = 4;
	col = 0;
	while (i < 8)
	{
		row = 3;
		count = 0;
		max = 0;
		while (row >= 0)
		{
			if (max < arr[row][col])
			{
				max = arr[row][col];
				count++;
			}
			row--;
		}
		if (count != g_watch[i])
			return (0);
		i++;
		col++;
	}
	return (1);
}

int		rowleft(int arr[SIZE][SIZE], int count, int row, int col)
{
	int i;
	int max;

	i = 8;
	row = 0;
	while (i < 12)
	{
		col = 0;
		max = 0;
		count = 0;
		while (col < 4)
		{
			if (max < arr[row][col])
			{
				max = arr[row][col];
				count++;
			}
			col++;
		}
		if (count != g_watch[i])
			return (0);
		i++;
		row++;
	}
	return (1);
}

int		rowright(int arr[SIZE][SIZE], int count, int row, int col)
{
	int i;
	int max;

	i = 12;
	row = 0;
	while (i < 16)
	{
		col = 3;
		count = 0;
		max = 0;
		while (col >= 0)
		{
			if (max < arr[row][col])
			{
				max = arr[row][col];
				count++;
			}
			col--;
		}
		if (count != g_watch[i])
			return (0);
		i++;
		row++;
	}
	return (1);
}

int		checking(int arr[SIZE][SIZE])
{
	int count;
	int row;
	int col;

	count = 0;
	row = 0;
	col = 0;
	if (!colup(arr, count, row, col))
		return (0);
	else if (!coldown(arr, count, row, col))
		return (0);
	else if (!rowleft(arr, count, row, col))
		return (0);
	else if (!rowright(arr, count, row, col))
		return (0);
	return (1);
}
