/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:51 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parsing.h"
#include "compute.h"
#include "display.h"
#include "matrix.h"
#include "stdio.h"

static int	ft_exit(int exit_code, t_scene scene)
{
	ft_free_scene(scene);
	return (exit_code);
}

int	main(int ac, char **av)
{
	t_scene	scene;
	int		canvas[SIZE_H][SIZE_V];

	ft_bzero(&scene, sizeof(scene));
	if (ac != 2)
		return (ft_error("wrong number of arguments", FALSE));
	if (ft_parse(&scene, av[1]))
		return (ft_exit(EXIT_FAILURE, scene));
	if (ft_compute(&scene, canvas))
		return (ft_exit(EXIT_FAILURE, scene));
	ft_free_scene(scene);
	ft_display(canvas);
	return (ft_exit(EXIT_SUCCESS, scene));
}
