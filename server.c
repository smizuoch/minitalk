/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:41:12 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/27 09:22:54 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sysexits.h>

void	action(int sig, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static int	j = 0;

	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
		i |= (1 << j);
	j ++;
	if (j == 8)
	{
		ft_putchar_fd(i, 1);
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	sigset_t			mask_block;
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid ();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigemptyset (&mask_block);
	sigaddset (&mask_block, SIGINT);
	sigaddset (&mask_block, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = 0;
	sa.sa_mask = mask_block;
	sa.sa_sigaction = action;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
