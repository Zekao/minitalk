/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:49:28 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/13 05:23:41 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_error_server(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("server : unexpected error.\n", 2);
	kill(pid, SIGUSR2);
	exit(0);
}

char	*ft_print(char *msg)
{
	if (msg)
	{
		ft_putstr_fd(msg, 1);
		free(msg);
	}
	return (NULL);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
	}
}
