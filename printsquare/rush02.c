/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:43:04 by sorkim            #+#    #+#             */
/*   Updated: 2020/11/21 16:15:31 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int g_col = 1;
int g_row = 1;

void	square(int x, int y)
{
	while (g_row <= y)
	{
		while (g_col <= x)
		{
			if ((g_col == 1 && g_row == 1) || (g_col == x && g_row == 1))
				ft_putchar('A');
			else if ((g_col == 1 && g_row == y) || (g_col == x && g_row == y))
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
	if (x > 0 && y > 0)
		square(x, y);
}
