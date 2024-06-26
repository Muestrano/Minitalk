/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:20:58 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/26 11:48:24 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Main
Get PID in argv[1]
Get message in argv[2]
Bit shift
while(i < 8) (c >> 1 & 1)
Sleep between 2 signals sent (else it's too fast for the server)
Global var, modified when receiving a signal from server
Kill to send signals

include printf atoi



struct sigaction	sa = { 0 };
sa.sa_flags = SA_RESTART;
sa.sa_handler = &handle_sigusr1; //function name
sigaction(SIGUSR1, &sa, NULL); //NULL because we don't use the old sigaction

kill(pid, SIGUSR1);

void handle_sigusr1();

*/

#include "minitalk.h"

void	sig_sender(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (i & 1)
			(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >> 1;
		i++;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int	serv_PID;
	int	len_msg;
	int	i;

	if (argc != 3 || !argv[2])
		return (ft_printf("An error has occured, please launch the program\
		 with this format :\t./client <server_PID> <message_to_send>\n"), 1);
	serv_PID = ft_atoi(argv[1]);
	len_msg = ft_strlen(argv[2]);
	sig_sender(serv_PID, len_msg);
	i = 0;
	while (argv[2][i])
	{
		sig_sender(serv_PID, argv[2][i]);
		i++;
	}
	sig_sender(serv_PID, 0);
	return (0);
}
