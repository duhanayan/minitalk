/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:06 by dayan             #+#    #+#             */
/*   Updated: 2022/03/15 16:06:26 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig)
{
	static char	c;
	static int	bit_sayisi;

	if (sig == SIGUSR1)
		c = c | 1;
	if (++bit_sayisi == 8)
	{
		bit_sayisi = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	write(1, "pid: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
	{
		pause();
	}
	return (0);
}
