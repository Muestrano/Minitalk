/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:35:51 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/14 18:23:15 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Check if there is an end of line in a string
Return the index of the \n
Return -1 if not
*/
int	check_endl(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin2(char *s4, char *s5)
{
	int		i;
	int		j;
	char	*s3;

	if (s4)
		s3 = (char *)malloc(sizeof(char) * (ft_strlen(s4) + ft_strlen(s5) + 1));
	else
		s3 = (char *)malloc(sizeof(char) * (ft_strlen(s5) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s4 && s4[i])
	{
		s3[i] = s4[i];
		i++;
	}
	j = 0;
	while (s5[j])
	{
		s3[i + j] = s5[j];
		j++;
	}
	s3[i + j] = 0;
	free(s4);
	return (s3);
}

char	*extract_line(char **stash, int endl)
{
	char	*next_line;
	char	*temp;

	if (endl == -1)
		endl = ft_strlen(*stash);
	next_line = ft_substr(*stash, 0, endl + 1);
	if (endl == (int)ft_strlen(*stash) && !(*stash)[0])
	{
		free(*stash);
		*stash = NULL;
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	temp = ft_substr(*stash, endl + 1, ft_strlen(*stash));
	free(*stash);
	*stash = temp;
	return (next_line);
}
