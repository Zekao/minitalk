/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:49 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/13 05:30:58 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	ft_check(char *str)
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

void	ft_error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("client: error\n", 2);
	exit(0);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error(str);
		return (0);
		i++;
	}
	return (1);
}

int	send_bit(int pid, char *str)
{
	static char	*msg = NULL;
	static int	s_pid = 0;
	static int	bit = 0;

	if (str)
		msg = ft_strdup(str);
	if (pid)
		s_pid = pid;
	if (!msg)
		ft_error(msg);
	if (msg[++bit / 8] == 0)
	{
		if (msg[bit / 8] == 0 && (0x80 >> (bit % 8) == 0))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				ft_error(msg);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			ft_error(msg);
		return (0);
	}
	if (!send_null(s_pid, msg))
		return (0);
	free(msg);
	printf("aaaaaaaaaaa");
	return (1);
}

