/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/10 14:57:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

//Scenario: Computing a point from a distance
t_point	ft_compute_point_on_ray(t_ray ray, double t)
{
	return (ft_p_translate(ray.origin, ft_v_scalar_prod(t, ray.direction)));
}

int	ft_get_color_pixel(t_scene *scene, size_t x, size_t y)
{
	t_ray		*ray;
	t_vector	direction;

	direction = ft_v_set((double)x * 10 / (double)SIZE_Y - 5 * (double)SIZE_X / (double)SIZE_Y, (double)y * 10 / (double)SIZE_Y - 5 , 15);
	// pour canva a 15 U de la cam et de hauteur 5U (cam situee a 0,0,-5, sphere de 1 a l'origine)
	ray = ft_create_ray(scene->camera.position, direction);
	ft_intersect_sphere(scene->objects, ray);
	if (ft_hit(&ray->inters_lst))
	{
		ft_free_inters_lst(ray->inters_lst);
		free(ray);
		return (0xFF0000);
	}
	ft_free_inters_lst(ray->inters_lst);
	free(ray);
	return (0xFFFFFF);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y])
{
	size_t	x;
	size_t	y;

	x = 0;
	ft_set_transform_sp(scene->objects); //a placer ailleurs ?
	scene->size_x = SIZE_X;
	while (x < scene->size_x)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			canvas[x][y] = ft_get_color_pixel(scene, x, y);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

// t_mat	ft_identity_matrix(void)
// {
// 	t_mat	identity;

// 	ft_bzero(&identity, sizeof(identity));
// 	identity.col = 4;
// 	identity.row = 4;
// 	identity.mat[0][0] = 1;
// 	identity.mat[1][1] = 1;
// 	identity.mat[2][2] = 1;
// 	identity.mat[3][3] = 1;
// 	return (identity);
// }
