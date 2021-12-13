/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:01:24 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/13 05:15:35 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

/*	Prototypes of my functions */
void	ft_error(char *str);
int		send_null(int pid, char *str);
int		send_bit(int pid, char *str);
void	ft_error_server(int pid, char *str);
char	*ft_print(char *msg);


/* My libft functions i needed */

int64_t	ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strdup(char *str);
int		ft_isdigit(int c);
int		ft_check(char *str);
char	*ft_straddchar(char *str, char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif 