/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejshin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:48:54 by hyejshin          #+#    #+#             */
/*   Updated: 2020/11/21 16:01:25 by hyejshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	g_row = 1;
int	g_col = 1;

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		while (g_row <= y)
		{
			while (g_col <= x)
			{
				if ((g_row == 1 || g_row == y) && g_col == 1)
					ft_putchar('A');
				else if ((g_row == 1 || g_row == y) && g_col == x)
					ft_putchar('C');
				else if (g_row == 1 || g_row == y || g_col == 1 || g_col == x)
					ft_putchar('B');
				else
					ft_putchar(' ');
				g_col++;
			}
			ft_putchar('\n');
			g_col = 1;
			g_row++;
		}
	}
}
