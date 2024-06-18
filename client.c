/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:20:58 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/18 14:53:12 by picarlie         ###   ########.fr       */
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
*/

#include "minitalk.h"



int	main(int argc, char **argv)
{
	int	serv_PID;

	if (argc != 3 || !argv[1] || !argv[2])
		return (ft_printf("An error has occured, please launch the program\
		 with this format :\t./client <server_PID> <message_to_send>\n"), 1);
	serv_PID = ft_atoi(argv[1]);
	return (0);
}
