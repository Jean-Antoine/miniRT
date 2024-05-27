/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:35:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 15:36:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_parse_scene(int fd, t_scene *scene)
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
			return (exit_code);
		exit_code = ft_parse_line(line, scene);
		free(line);
		if (exit_code)
			break ;
	}
	get_next_line(fd, TRUE);
	close(fd);
	return (exit_code);
}


int	ft_parse(t_scene *scene, char *file)
{
	int	fd;

	ft_bzero(scene, sizeof(t_scene));
	fd = ft_open_file(file);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (ft_parse_scene(fd, scene))
		return (EXIT_FAILURE);
	// if (ft_check_scene(scene))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
