/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:48:52 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/13 05:29:33 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <sys/signal.h>



void	handler_sigusr(int sigusr, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*msg = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (sigusr == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (sigusr == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
		{
			msg = ft_straddchar(msg, c);
			printf("debug : %s\n", msg);
		}
		else
			msg = ft_print(msg);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		ft_error_server(pid, msg);
}

int	main(void)
{
	struct sigaction sa;
	// sigset_t	block_mask;

	// sigemptyset(&block_mask);
	// sigaddset(&block_mask, SIGINT);
	// sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	// sa.sa_mask = block_mask;
	sa.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}