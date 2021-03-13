#include "ft_h.h"

extern int		**g_sol;
extern int		**g_map;
extern char		g_str[3];
extern int		g_row;
extern int		g_col;
extern int		g_obs_size;
extern t_point	*g_obs;
extern t_answer	g_ans;

void	ft_solve_initialize(void)
{
	int i;
	int j;

	i = -1;
	g_sol = (int **)malloc(sizeof(int *) * g_row);
	while (++i < g_row)
		g_sol[i] = (int *)malloc(sizeof(int) * (g_col + 1));
	i = -1;
	while (++i < g_row)
	{
		j = -1;
		while (++j <= g_col)
			g_sol[i][j] = 1;
	}
	i = -1;
	while (++i < g_obs_size)
		g_sol[g_obs[i].row][g_obs[i].col] = 0;
}

void	ft_judge_size(int i, int j)
{
	int size;

	if (g_sol[i - 1][j] != 1 &&
		g_sol[i - 1][j - 1] != 1 && g_sol[i][j - 1] != 1)
	{
		size = (g_sol[i - 1][j] < g_sol[i - 1][j - 1]) ?
			g_sol[i - 1][j] : g_sol[i - 1][j - 1];
		size = (size < g_sol[i][j - 1]) ? size : g_sol[i][j - 1];
		size++;
		g_sol[i][j] = size;
	}
	else
		g_sol[i][j] = 2;
}

void	ft_search_max(void)
{
	int i;
	int j;
	int max;

	i = 0;
	max = -1;
	while (i < g_row)
	{
		j = 0;
		while (j <= g_col)
		{
			if (max < g_sol[i][j])
			{
				g_ans.start_row = i - g_sol[i][j] + 1;
				g_ans.start_col = j - g_sol[i][j] + 1;
				g_ans.len = g_sol[i][j];
				max = g_sol[i][j];
			}
			j++;
		}
		i++;
	}
}

void	ft_solve_problem(void)
{
	int i;
	int j;

	i = 0;
	g_ans.start_row = 0;
	g_ans.start_col = 0;
	g_ans.len = 0;
	ft_solve_initialize();
	while (++i < g_row)
	{
		j = 0;
		while (++j <= g_col)
		{
			if (g_sol[i][j] != 0)
			{
				if (g_sol[i - 1][j] != 0 &&
					g_sol[i - 1][j - 1] != 0 && g_sol[i][j - 1] != 0)
					ft_judge_size(i, j);
			}
		}
	}
	ft_search_max();
}
