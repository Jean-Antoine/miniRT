/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:28:55 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/24 18:04:59 by jeada-si         ###   ########.fr       */
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
	up = ft_v_cross_prod(left, dir);
	view.mat[0][0] = left.x; 	view.mat[0][1] = left.y; 	view.mat[0][2] = left.z;
	view.mat[1][0] = up.x; 		view.mat[1][1] = up.y; 		view.mat[1][2] = up.z;
	view.mat[2][0] = -dir.x; 	view.mat[2][1] = -dir.y; 	view.mat[2][2] = -dir.z;
	view.mat[3][3] = 1;
	view = ft_mat_prod(
		view,
		ft_translation(
			-position.x,
			-position.y,
			-position.z)
	);
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
		camera->half_height= half_view;
	}
	camera->pixel_size = (camera->half_width * 2.0) / (double) SIZE_H;
	printf("%f\n", camera->pixel_size);
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


// //tests github
// void	normalize_vector(t_vector *vector)
// {
// 	double len;

// 	len = sqrt(vector->x * vector->x + vector->y
// 	* vector->y + vector->z * vector->z);
// 	vector->x /= len;
// 	vector->y /= len;
// 	vector->z /= len;
// }

// t_ray		create_ray(t_vector origin, t_vector direction)
// {
// 	t_ray result;

// 	result.origin = origin;
// 	result.direction = direction;
// 	return (result);
// }

// t_vector	cross_product(t_vector a, t_vector b)
// {
// 	t_vector result;

// 	result.x = a.y * b.z - a.z * b.y;
// 	result.y = a.z * b.x - a.x * b.z;
// 	result.z = a.x * b.y - a.y * b.x;
// 	return (result);
// }

// t_mat	look_at(t_vector origin, t_vector cam_vector)
// {
// 	t_mat	m;
// 	t_vector		random;
// 	t_vector		right;
// 	t_vector		up;

// 	m = ft_matrix(4, 4);
// 	random = ft_vector(0, 1, 0);
// 	normalize_vector(&random);
// 	right = cross_product(random, cam_vector);
// 	normalize_vector(&right);
// 	up = cross_product(cam_vector, right);
// 	normalize_vector(&up);
// 	m.mat[0][0] = right.x;
// 	m.mat[0][1] = right.y;
// 	m.mat[0][2] = right.z;
// 	m.mat[1][0] = up.x;
// 	m.mat[1][1] = up.y;
// 	m.mat[1][2] = up.z;
// 	m.mat[2][0] = cam_vector.x;
// 	m.mat[2][1] = cam_vector.y;
// 	m.mat[2][2] = cam_vector.z;
// 	m.mat[3][0] = origin.x;
// 	m.mat[3][1] = origin.y;
// 	m.mat[3][2] = origin.z;
// 	return (m);
// }

// t_vector		get_direction(int x, int y, t_camera camera)
// {
// 	double fov_coeff;
// 	double aspect_ratio;
// 	double p_x;
// 	double p_y;

// 	fov_coeff = tan((double)camera.fov / 2 * M_PI / 180);
// 	aspect_ratio = (double)SIZE_H / (double)SIZE_V;
// 	p_x = (2 * (x + 0.5) / (double)SIZE_H - 1) * aspect_ratio * fov_coeff;
// 	p_y = (1 - 2 * (y + 0.5) / (double)SIZE_V) * fov_coeff;
// 	return (ft_vector(p_x, p_y, 1));
// }

// t_vector		multiply_by_matrix(t_vector p, t_mat m)
// {
// 	t_vector res;

// 	res.x = p.x * m.mat[0][0] + p.y * m.mat[1][0] + p.z * m.mat[2][0] + m.mat[3][0];
// 	res.y = p.x * m.mat[0][1] + p.y * m.mat[1][1] + p.z * m.mat[2][1] + m.mat[3][1];
// 	res.z = p.x * m.mat[0][2] + p.y * m.mat[1][2] + p.z * m.mat[2][2] + m.mat[3][2];
// 	return (res);
// }



// t_ray		ray_to_pixel(int x, int y, t_camera *camera1)
// {
// 	t_vector		origin;
// 	t_vector		direction;
// 	t_mat			c2w;
// 	t_camera	camera;

// 	camera = *camera1;
// 	c2w = look_at(camera.position, camera.direction);
// 	origin = multiply_by_matrix(ft_vector(0, 0, 0), c2w);
// 	direction = get_direction(x, y, camera);
// 	direction = multiply_by_matrix(direction, c2w);
// 	direction = ft_p_to_v(origin, direction);
// 	normalize_vector(&direction);
// 	return (ft_ray(origin, direction));
// }
