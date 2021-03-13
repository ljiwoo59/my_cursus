#include "ft_h.h"

int			**g_sol;
char		*g_file;
char		g_str[3];
int			g_row = 0;
int			g_col = 0;
int			g_obs_size = 0;
int			g_i = 0;
t_point		*g_obs;
t_answer	g_ans;

void	ft_initialize(void)
{
	int i;

	i = -1;
	if (g_sol)
	{
		while (++i < g_row)
			free(g_sol[i]);
	}
	free(g_sol);
	if (g_file)
		free(g_file);
	if (g_obs)
		free(g_obs);
	g_obs_size = 0;
	g_ans.start_row = 0;
	g_ans.start_col = 0;
	g_ans.len = 0;
	g_row = 0;
	g_col = 0;
}

int		ft_user_input(void)
{
	ft_input_stream();
	if (checkinfo())
	{
		if (checkmap())
		{
			ft_solve_problem();
			ft_print();
			ft_initialize();
		}
		else
		{
			write(1, "map error\n", 10);
			return (0);
		}
	}
	else
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}

int		main(int ac, char *av[])
{
	int i;

	if (ac == 1)
		ft_user_input();
	else
	{
		i = 0;
		while (++i < ac)
		{
			filetostr(av[i]);
			if (checkinfo())
			{
				if (checkmap())
				{
					ft_solve_problem();
					ft_print();
					ft_initialize();
				}
				else
					write(1, "map error\n", 10);
			}
			else
				write(1, "map error\n", 10);
		}
	}
}
