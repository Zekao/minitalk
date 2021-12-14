/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:01:00 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/14 17:46:40 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_error(void)
{
	ft_putstr_fd("client: unable to send the signal to the server\n", 2);
	exit (0);
}
static void	send_message(int pid, char *msg)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(msg);
	while (i <= size)
	{
		j = 7;
		while (j > -1)
		{
			if ((msg[i] >> j) & 1)
				if (kill(pid, SIGUSR1) < 0)
					ft_error();
			if (!((msg[i] >> j) & 1))
				if (kill(pid, SIGUSR2) < 0)
					ft_error();
			j--;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || ft_check(argv[1]) == 0)
	{
		ft_putstr_fd("client: invalid arguments.\n", 2);
		ft_putstr_fd("correct format: [./client <PID> <STR>].\n", 2);
		exit (0);
	}
	if ( argc == 3 && ft_atoi(argv[1]) >= 4294967295)
	{
		ft_putstr_fd("Incorrect PID.\n", 2);
		exit (0);
	}
	else
		send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}