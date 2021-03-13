/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:11:27 by ji-lee            #+#    #+#             */
/*   Updated: 2020/11/21 15:52:05 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int g_col = 1;
int g_row = 1;

void	line(int x, int y)
{
	while (g_col <= x || g_row <= y)
	{
		if (g_col == 1 || g_row == 1)
			ft_putchar('A');
		else if (g_col == x || g_row == y)
			ft_putchar('C');
		else
			ft_putchar('B');
		g_row++;
		g_col++;
		if (x == 1)
			ft_putchar('\n');
	}
	if (y == 1 && x != 1)
		ft_putchar('\n');
}

void	square(int x, int y)
{
	while (g_row <= y)
	{
		while (g_col <= x)
		{
			if (((g_col == 1 && g_row == 1) || (g_col == x && g_row == y)))
				ft_putchar('A');
			else if ((g_col == x && g_row == 1) || (g_col == 1 && g_row == y))
				ft_putchar('C');
			else if (!(g_col == 1 || g_col == x || g_row == 1 || g_row == y))
				ft_putchar(' ');
			else
				ft_putchar('B');
			g_col++;
		}
		ft_putchar('\n');
		g_row++;
		g_col = 1;
	}
}

void	rush(int x, int y)
{
	if (x == 1 || y == 1)
		line(x, y);
	else if (x > 0 && y > 0)
		square(x, y);
}
