/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:01:24 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/14 18:08:44 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/signal.h>

# define MAX_PID 4294967295 
/* ======	Libft imported functions	====== */

int64_t	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_straddchar(char *str, char c);

/* ======								===== */

#endif