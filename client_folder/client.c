/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:01:10 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/13 05:21:55 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler_sigusr(int sigusr)
{
	int	end;

	end = 0;
	if (sigusr == SIGUSR1)
		end = send_bit(0, 0);
	else if (sigusr == SIGUSR2)
	{
		ft_putstr_fd("client: server error.\n", 2);
		exit(0);
	}
	if (end)
	{
		ft_putstr_fd("client: done\n", 1);
		exit (0);
	}
	
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction sa;
	
	pid = 0;
	pid++;
	if (argc != 3 || ft_check(argv[1]) == 0)
	{
		ft_putstr_fd("client : invalid arguments.\n", 2);
		ft_putstr_fd("correct format : [./client <PID> <STR>].\n", 2);
		exit (0);
	}
	if ( argc == 3 && ft_atoi(argv[1]) >= 4294967295)
	{
		ft_putstr_fd("Incorrect PID.\n", 2);
		exit (0);
	}
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);	
	sigaction(SIGUSR2, &sa, NULL);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while(1)
		pause();
}