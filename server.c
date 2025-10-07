/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:50:31 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/09/10 15:36:23 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	signal_handler(int sig)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	current_char <<= 1;
	if (sig == SIGUSR1)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("\n");
			ft_printf("\nWaiting for messages...\n\n");
		}
		else
			ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\nServer PID: %d\n", pid);
	ft_printf("\nWaiting for messages...\n\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
