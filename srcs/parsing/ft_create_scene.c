/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:57:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 11:16:01 by jeada-si         ###   ########.fr       */
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
			return (exit_code);
		exit_code = ft_fill_scene(line, scene);
		free(line);
		if (exit_code)
			break ;
	}
	get_next_line(fd, TRUE);
	close(fd);
	return (exit_code);
}
