/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejshin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:08:21 by hyejshin          #+#    #+#             */
/*   Updated: 2020/11/21 16:03:07 by hyejshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int g_row = 1;
int g_col = 1;

void	line(int x, int y)
{
	while (g_row <= y || g_col <= x)
	{
		if ((g_row == 1 && g_col == 1))
			ft_putchar('/');
		else if (g_row == y || g_col == x)
			ft_putchar('\\');
		else
			ft_putchar('*');
		g_row++;
		g_col++;
		if (y != 1)
			ft_putchar('\n');
	}
	if (y == 1)
		ft_putchar('\n');
}

void	square(int x, int y)
{
	while (g_row <= y)
	{
		while (g_col <= x)
		{
			if ((g_row == 1 && g_col == 1) || (g_row == y && g_col == x))
				ft_putchar('/');
			else if ((g_row == 1 && g_col == x) || (g_row == y && g_col == 1))
				ft_putchar('\\');
			else if (g_row == 1 || g_row == y || g_col == 1 || g_col == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			g_col++;
		}
		ft_putchar('\n');
		g_col = 1;
		g_row++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		if (x == 1 || y == 1)
			line(x, y);
		else
			square(x, y);
	}
}
