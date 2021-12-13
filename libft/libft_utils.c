/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:14:13 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/13 03:14:13 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int64_t	ft_atoi(const char *str)
{
	int			i;
	int64_t		r;
	int			verif;

	r = 0;
	verif = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			verif = -verif;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * verif);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
}

char	*ft_strdup(char *str)
{
	char	*str2;

	int	i;
	i = 0;
	while (str[i])
		i++;
	str2 = malloc(sizeof(char) * (i + 1));
	if (!str2)
		return (NULL);
	i = 0;
	while (str[i++])
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

char	*ft_straddchar(char *str, char c)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	newstr = malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	i++;
	newstr[i] = '\0';
	return (newstr);
}