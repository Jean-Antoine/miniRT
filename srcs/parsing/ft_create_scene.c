/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:57:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 18:07:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_create_scene(int fd, t_scene *scene)
{
	char	*line;
	int		exit_code;

	if (fd < 0 || !scene)
		return (EXIT_FAILURE);
	exit_code = EXIT_SUCCESS;
	while (TRUE)
	{
		line = get_next_line(fd, FALSE);
		if (!line)
			break ;
		if (ft_fill_scene(line, scene) == EXIT_FAILURE)
		{
			exit_code = EXIT_FAILURE;
			free(line);
			break ;
		}
		free(line);
	}
	get_next_line(fd, TRUE);
	close(fd);
	return (exit_code);
}
