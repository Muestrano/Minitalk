/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:20:55 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/26 11:48:08 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Main
Display PID when launched
Catch signals
Convert signals into chars
Print the string when complete


include printf atoi
*/

#include "minitalk.h"

void	sig_handler()
{
	static int	i;
	long int	len_msg;

	i++;
	if (i == 8)
	{
		len_msg = (long int)malloc(sizeof(long int));
		if (!len_msg)
			return (NULL);
		len_msg = 
	}
	else if (! i %% 8)
	
}

int	main(int argc, char **argv)
{
	int	i;
	int	len_msg;

	ft_printf("The server's PID is : %d.\n", getpid());
	signal(SIGUSR1, sig_handler);
	i = 0;
	while (i < 8)
	{
		
		i++;
	}
	return (0);
}
