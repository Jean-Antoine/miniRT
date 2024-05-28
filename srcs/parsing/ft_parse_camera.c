/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:26:11 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/28 13:39:53 by jeada-si         ###   ########.fr       */
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
		return (ft_error("more than one camera", FALSE));
	if (ft_tabsize(args) != 4)
		return (ft_error("wrong number of parameters", FALSE));
	exit_code = (ft_set_point(&dest->position, args[1])
			|| ft_set_vector(&dest->direction, args[2])
			|| ft_set_scalar(&dest->fov, args[3]));
	if (exit_code == EXIT_SUCCESS
		&& (dest->fov < 0
			|| dest->fov > 180))
		return (ft_error("FOV must be between 0 and 180", FALSE));
	return (exit_code);
}
