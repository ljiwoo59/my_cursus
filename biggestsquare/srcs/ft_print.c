#include "ft_h.h"

extern t_point	*g_obs;
extern t_answer	g_ans;
extern char		*g_file;
extern char		g_str[3];
extern int		g_row;
extern int		g_col;
extern int		g_obs_size;

char			**ft_initialize_map(void)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * g_row + 1);
	i = 0;
	while (i < g_row)
	{
		map[i] = (char *)malloc(sizeof(char) * g_col + 1);
		i++;
	}
	i = 0;
	while (i < g_row)
	{
		j = 0;
		while (j <= g_col)
		{
			map[i][j] = g_str[0];
			j++;
		}
		i++;
	}
	return (map);
}

void			ft_fill_obs(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_obs_size)
	{
		map[g_obs[i].row][g_obs[i].col] = g_str[1];
		i++;
	}
	i = 0;
	while (i < g_ans.len)
	{
		j = 0;
		while (j < g_ans.len)
		{
			map[g_ans.start_row + i][g_ans.start_col + j] = g_str[2];
			j++;
		}
		i++;
	}
}

void			ft_print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_row)
	{
		j = 0;
		while (j <= g_col)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	i = 0;
	while (i < g_row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void			ft_print(void)
{
	char **map;

	map = ft_initialize_map();
	ft_fill_obs(map);
	ft_print_map(map);
}

void			ft_input_stream(void)
{
	int		i;
	char	c;

	i = 0;
	g_file = (char *)malloc(sizeof(char) * 10484448);
	while (read(0, &c, 1) != 0)
	{
		g_file[i] = c;
		g_file[i + 1] = 0;
		i++;
	}
}
