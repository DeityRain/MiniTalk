/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:33:47 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/09/11 07:03:58 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <errno.h>
#include <signal.h>
#include <unistd.h>

int	is_valid_pid(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i > 10)
		return (0);
	return (1);
}

int	pid_exists(int pid)
{
	if (kill(pid, 0) == 0)
		return (1);
	else
	{
		if (errno == ESRCH)
		{
			write(2, "\nError: No such process\n\n", 24);
			return (0);
		}
		else if (errno == EPERM)
		{
			write(2, "\nError: Permission denied\n\n", 26);
			return (0);
		}
		else
		{
			write(2, "\nError: Invalid PID\n\n", 20);
			return (0);
		}
	}
}

int	validate_and_convert_pid(char *pid_str)
{
	int	pid;

	if (!is_valid_pid(pid_str))
	{
		write(2, "\nError: Invalid PID format\n\n", 27);
		return (-1);
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
	{
		write(2, "\nError: PID must be positive\n\n", 29);
		return (-1);
	}
	if (!pid_exists(pid))
	{
		write(2, "\nError: Process does not exist\n\n", 32);
		return (-1);
	}
	return (pid);
}

void	send_signal(int server_pid, char character)
{
	int	bit_position;
	int	signal_to_send;

	bit_position = 7;
	while (bit_position >= 0)
	{
		if (character & (1 << bit_position))
			signal_to_send = SIGUSR1;
		else
			signal_to_send = SIGUSR2;
		if (kill(server_pid, signal_to_send) == -1)
		{
			write(2, "\nError: Failed to send signal\n\n", 30);
			exit(1);
		}
		usleep(250);
		bit_position--;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("\nUsage: ./client <server_pid> <message>\n\n");
		return (1);
	}
	server_pid = validate_and_convert_pid(argv[1]);
	if (server_pid == -1)
		return (1);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_signal(server_pid, message[i]);
		i++;
	}
	send_signal(server_pid, '\0');
	ft_printf("\nMessage sent successfully!\n\n");
	return (0);
}
