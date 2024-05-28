/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:26:11 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/28 12:33:15 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_parse_camera(char **args, t_camera *dest)
{
	static size_t	nb_cameras = 0;
	int				exit_code;

	if (ft_strcmp(args[0], "C"))
		return (2);
	if (++nb_cameras > 1)
		return (ft_error("Invalid data\n", FALSE));
	if (ft_tabsize(args) != 4)
		return (ft_error("Invalid data\n", FALSE));
	exit_code = (ft_set_point(&dest->position, args[1])
			+ ft_set_vector(&dest->direction, args[2])
			+ ft_set_scalar(&dest->fov, args[3]));
	if (exit_code == EXIT_SUCCESS
		&& (dest->fov < 0
			|| dest->fov > 180))
		return (ft_error("Invalid data\n", FALSE));
	return (exit_code != 0);
}
