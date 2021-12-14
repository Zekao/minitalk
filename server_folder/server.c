/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:07:59 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/14 17:57:50 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_message(int signum)
{
	static  char chr = 0x00;
	static int	size = 7;
	
	if (signum == SIGUSR1)
	{
		chr += (1 << size);
		size--;
	}
	else if (signum == SIGUSR2)
		size--;
	if (size < 0)
	{
		ft_putchar_fd(chr, 1);
		if (!chr)
			ft_putchar_fd('\n', 1);
		chr = 0x00;
		size = 7;
	}
}

int	main(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
		pause();
	return (0);
}
