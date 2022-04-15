/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:00 by dayan             #+#    #+#             */
/*   Updated: 2022/03/15 16:06:02 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(int pid, char *str)
{
	int		x;
	char	c;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		x = 8;
		c = str[i];
		while (x--)
		{
			if (c >> x & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	sayi;
	int	i;

	sayi = 0;
	i = 0;
	while (str[i] != '\0')
	{
		sayi = (str[i] - '0') + (sayi * 10);
		i++;
	}
	return (sayi);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "2 argüman girmelisiniz.\n", 24);
		write(1, "\n", 1);
		return (0);
	}
	ft_kill(ft_atoi(argv[1]), argv[2]);
	ft_kill(ft_atoi(argv[1]), "\n");
}
