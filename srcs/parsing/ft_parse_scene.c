/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:35:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 11:52:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_parse_scene(t_scene *scene, char *file)
{
	int	fd;
	ft_bzero(scene, sizeof(t_scene));
	fd = ft_open_file(file);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (ft_create_scene(fd, scene))
		return (EXIT_FAILURE);
	// if (ft_check_scene(scene))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
