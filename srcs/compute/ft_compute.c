/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/06 16:45:45 by lpaquatt         ###   ########.fr       */
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

	direction = ft_v_set((double)x * 10 / (double)scene->size_y - 5 * (double)SIZE_X / (double)scene->size_y, (double)y * 10 / (double)scene->size_y - 5 , 15);
	// pour canva a 15 U de la cam et de hauteur 5U (cam situee a 0,0,-5, sphere de 1 a l'origine)
	ray = ft_create_ray(scene->camera.position, direction);
	// if (x == 0 && y == 0)
	// {
	// 	printf("TEST	> ray (0,0) : \n");
	// 	printf("	> origin = ");
	// 	ft_tuple_print(ray->origin);
	// 	printf("	> direction = ");
	// 	ft_tuple_print(ray->direction);
	// }
	// 	if (x == 400 && y == 225)
	// {
	// 	printf("TEST	> ray (400,225) : \n");
	// 	printf("	> origin = ");
	// 	ft_tuple_print(ray->origin);
	// 	printf("	> direction = ");
	// 	ft_tuple_print(ray->direction);
	// }
	ft_intersect_sphere(scene->objects, ray);
	if (ft_hit(&ray->inters_lst))
	{
		return (0xFF0000);
	}
	return (0x808a9f);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y])
{
	size_t	x;
	size_t	y;

	x = 0;
	scene->size_y = SIZE_Y * (size_t)scene->camera.fov / 180;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < scene->size_y)
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
