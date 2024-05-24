/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:35:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 18:04:47 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_parse_scene(t_scene *scene, int ac, char **av)
{
	ft_memset(scene, 0, sizeof(t_scene));
	if (ac != 2)
	{
		ft_putstr_fd("Error : wrong number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_create_scene(ft_open_file(av[1]), scene) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (ft_check_scene(scene) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
