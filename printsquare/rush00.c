/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejshin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:25:46 by hyejshin          #+#    #+#             */
/*   Updated: 2020/11/21 16:00:29 by hyejshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int g_row = 1;
int g_col = 1;

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		while (g_col <= y)
		{
			while (g_row <= x)
			{
				if ((g_row == 1 || g_row == x) && (g_col == 1 || g_col == y))
					ft_putchar('o');
				else if (g_row == 1 || g_row == x)
					ft_putchar('|');
				else if (g_col == 1 || g_col == y)
					ft_putchar('-');
				else
					ft_putchar(' ');
				g_row++;
			}
			ft_putchar('\n');
			g_row = 1;
			g_col++;
		}
	}
}
