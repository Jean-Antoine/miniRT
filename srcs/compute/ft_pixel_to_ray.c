/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:28:55 by jeada-si          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/03 14:07:47 by lpaquatt         ###   ########.fr       */
=======
/*   Updated: 2024/07/03 11:43:43 by jeada-si         ###   ########.fr       */
>>>>>>> 46b5a25 (cone cyl)
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

// Considering canvas is at z = -1
static t_mat	ft_mat_view_inv(t_vector dir, t_point position)
{
	t_vector	left;
	t_vector	up;
	t_mat		view;

	view = ft_matrix(4, 4);
	dir = ft_v_normalize(dir);
	left = ft_v_cross_prod(dir, ft_vector(0, 1, 0));
	if (ft_v_norm(left) < TOLERANCE)
		left = ft_v_cross_prod(dir, ft_vector(0, 0, 1));
	up = ft_v_cross_prod(left, dir);
	dir = ft_v_scalar_prod(-1, dir);
	view = ft_mat_view(dir, left, up, ft_point(0, 0, 0));
	view = ft_mat_prod(
			view,
			ft_translation(-position.x, -position.y, -position.z));
	return (ft_mat_inv(view));
}

static void	ft_pixel_size(t_camera *camera)
{
	double	half_view;
	double	aspect;
	double	fov_radian;

	camera->view_inv = ft_mat_view_inv(camera->direction, camera->position);
	aspect = (double) SIZE_H / (double) SIZE_V;
	fov_radian = (camera->fov / 180.0) * M_PI;
	half_view = tan(fov_radian / 2.0);
	camera->half_width = half_view;
	camera->half_height = half_view / aspect;
	if (aspect < 1.0)
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2.0) / (double) SIZE_H;
}

static t_ray	ft_compute_ray(double x, double y, t_mat view_inv)
{
	t_point			pixel;
	t_vector		direction;
	t_point			origin;

	pixel = ft_mat_prod_tup(view_inv, ft_point(x, y, -1));
	origin = ft_mat_prod_tup(view_inv, ft_point(0, 0, 0));
	direction = ft_p_to_v(origin, pixel);
	direction = ft_v_normalize(direction);
	return (ft_ray(origin, direction));
}

t_ray	ft_pixel_to_ray(int px, int py, t_camera *camera)
{
	static int		tbd = 0;
	double			x_offset;
	double			y_offset;
	double			x;
	double			y;

	if (!tbd++)
		ft_pixel_size(camera);
	x_offset = ((double) px + (double) 0.5) * camera->pixel_size;
	y_offset = ((double) py + (double) 0.5) * camera->pixel_size;
	x = camera->half_width - x_offset;
	y = camera->half_height - y_offset;
	return (ft_compute_ray(x, y, camera->view_inv));
}
