/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:56:11 by ji-lee            #+#    #+#             */
/*   Updated: 2020/11/22 16:34:27 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		power(int base, int exp);
int		ft_atoi(char *str);
int		counting(char *str);

int		main(int argc, char *argv[])
{
	if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argc == 1)
		rush(5, 5);
	return (0);
}

int		power(int base, int exp)
{
	int i;

	i = 1;
	while (exp > 0)
	{
		i *= base;
		exp--;
	}
	return (i);
}

int		counting(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		count++;
		i++;
	}
	return (count);
}

int		ft_atoi(char *str)
{
	int i;
	int count;
	int number;

	i = 0;
	number = 0;
	count = counting(str);
	while (str[i])
	{
		if (str[i] == '+')
			i++;
		number += (str[i] - '0') * power(10, count - 1);
		i++;
		count--;
	}
	return (number);
}
