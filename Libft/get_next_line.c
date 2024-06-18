/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:36:01 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/14 16:42:22 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_buff_malloc(void)
{
	int		i;
	char	*buffer;

	if (BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

char	*free_them_all(char *stash, char *buffer)
{
	(void)stash;
	if (buffer)
		free(buffer);
	return (NULL);
}

char	*buff_to_null(char *buffer)
{
	int	i;

	i = 0;
	while (buffer [i])
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buffer;
	int			read_val;
	int			endl;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	buffer = ft_buff_malloc();
	if (!buffer)
		return (NULL);
	endl = check_endl(stash);
	read_val = 1;
	while (endl == -1 && read_val > 0 && BUFFER_SIZE > 0)
	{
		buffer = buff_to_null(buffer);
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val == -1 || (!read_val && !stash))
			return (free_them_all(stash, buffer));
		if (read_val)
			stash = ft_strjoin2(stash, buffer);
		endl = check_endl(stash);
	}
	free(buffer);
	return (extract_line(&stash, endl));
}
