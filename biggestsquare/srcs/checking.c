#include "ft_h.h"

extern char		*g_file;
extern int		g_row;
extern int		g_col;
extern char		g_str[3];
extern int		g_i;
extern int		g_obs_size;
extern t_point	*g_obs;
extern t_answer	g_ans;

int		is_char(char *str, char c)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (i < 2)
	{
		if (str[i] == c)
			flag++;
		i++;
	}
	if (flag != 0)
		return (1);
	else
		return (0);
}

int		checkinfo(void)
{
	char	num_buf[30710];
	int		char_start;
	int		i;

	g_i = 0;
	while (g_file[g_i] != '\n')
	{
		if (!(g_file[g_i] >= 32 && g_file[g_i] <= 126))
			return (0);
		num_buf[g_i] = g_file[g_i];
		g_i++;
	}
	if (g_i < 4)
		return (0);
	char_start = g_i - 3;
	num_buf[char_start] = 0;
	if (ft_atoi(num_buf) == 0)
		return (0);
	g_row = ft_atoi(num_buf);
	i = 0;
	while (char_start < g_i)
		g_str[i++] = g_file[char_start++];
	if (is_samechar(g_str) == 1)
		return (0);
	return (1);
}

int		checkcheck(int *nlcount, int *colcount)
{
	while (g_file[g_i])
	{
		g_i++;
		*colcount = -1;
		while (g_file[g_i] != '\n' && g_file[g_i])
		{
			if (!is_char(g_str, g_file[g_i]))
				return (0);
			(*colcount)++;
			if (g_file[g_i] == g_str[1])
				g_obs_size++;
			g_i++;
		}
		if (!(g_file[g_i]))
			break ;
		if (g_col == 0)
			g_col = *colcount;
		if (g_col != *colcount)
			return (0);
		(*nlcount)++;
	}
	return (1);
}

void	put_obs(int *temp, int *colcount, int *nlcount)
{
	int i;

	i = 0;
	while (g_file[*temp])
	{
		(*temp)++;
		*colcount = -1;
		while (g_file[*temp] != '\n' && g_file[*temp])
		{
			(*colcount)++;
			if (g_file[*temp] == g_str[1])
			{
				g_obs[i].row = *nlcount;
				g_obs[i].col = *colcount;
				i++;
			}
			(*temp)++;
		}
		(*nlcount)++;
	}
}

int		checkmap(void)
{
	int nlcount;
	int colcount;
	int temp;

	nlcount = 0;
	colcount = -1;
	temp = g_i;
	if (!checkcheck(&nlcount, &colcount))
		return (0);
	if (g_row != nlcount)
		return (0);
	g_obs = (t_point *)malloc(sizeof(t_point) * g_obs_size);
	nlcount = 0;
	put_obs(&temp, &colcount, &nlcount);
	return (1);
}
