#ifndef FT_H_H
# define FT_H_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"

typedef struct	s_point
{
	int row;
	int col;
}				t_point;

typedef struct	s_answer
{
	int start_row;
	int start_col;
	int len;
}				t_answer;

char			**ft_initialize_map(void);
void			ft_fill_obs(char **map);
void			ft_print_map(char **map);
void			ft_print(void);
void			ft_solve_problem(void);
void			ft_get_line(int i, int j, int *flag);
void			ft_get_square(int i, int j, int len);
void			ft_solve_problem(void);
void			ft_input_stream(void);
void			filetostr(char *str);
int				checkmap(void);
int				is_samechar(char *str);
int				checkinfo(void);
int				ft_atoi(char *str);

#endif
