/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:35:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/28 12:00:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_error_line(int i, char *str)
{
	ft_putstr_fd("line ", STDERR_FILENO);
	ft_putnbr_fd(i, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

static int	ft_parse_scene(int fd, t_scene *scene)
{
	char	*line;
	int		exit_code;
	int		i;

	if (fd < 0 || !scene)
		return (EXIT_FAILURE);
	exit_code = EXIT_SUCCESS;
	i = 0;
	while (++i)
	{
		line = get_next_line(fd, FALSE);
		if (!line)
			break ;
		exit_code = ft_parse_line(line, scene);
		if (exit_code)
			ft_error_line(i, line);
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
