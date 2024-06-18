/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:20:55 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/18 14:43:07 by picarlie         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	ft_printf("The server's PID is : %d.\n", getpid());
	return (0);
}
