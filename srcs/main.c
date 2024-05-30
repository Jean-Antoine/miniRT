/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/30 14:26:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_exit(int exit_code, t_scene scene)
{
	ft_free_scene(scene);
	return (exit_code);
}

int	main(int ac, char **av)
{
	t_scene	scene;
	int		canvas[SIZE_X][SIZE_Y_MAX];

	if (ac != 2)
		return (ft_error("wrong number of arguments", FALSE));
	if (ft_parse(&scene, av[1]))
		return (ft_exit(EXIT_FAILURE, scene));
	ft_bzero(canvas, sizeof(canvas));
	// if (ft_compute(&scene, canvas))
	// 	return (ft_exit(EXIT_FAILURE, scene));
	return (ft_exit(EXIT_SUCCESS, scene));
}
