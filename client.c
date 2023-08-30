/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:40:39 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/27 11:58:44 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sysexits.h>

void	re_send(int pid, char *message, int i, int j)
{
	while (j < 8)
	{
		if (message[i] & (1 << j))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep (600);
		j++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (message[i])
	{
		while (j < 8)
		{
			if (message[i] & (1 << j))
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep (600);
			j++;
		}
		j = 0;
		i++;
	}
	re_send(pid, message, i, j);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client [pid] [message]", 2);
		return (1);
	}
	if (ft_atoi(argv[1]) < 100 || ft_atoi(argv[1]) > 99998)
	{
		ft_putendl_fd("Invalid PID", 2);
		return (1);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
