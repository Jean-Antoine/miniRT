/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/21 15:32:49 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_ray		ray_to_pixel(int x, int y, t_camera *camera1);//
int			intersect_sphere(t_ray ray, t_object sphere, double *t);

int	ft_color_to_int(t_color color) 
{
	return (((int) color.x << 16) | (((int) color.y / 255) << 8) | ((int)color.z / 255));
}


int	ft_get_color_pixel(t_scene *scene, size_t x, size_t y)
{
	t_ray		ray;
	t_inters	*hit;
	t_color		color;
	t_inters	*hit;
	t_color		color;	

	static	int	i = -1;
	i++;
	ray = ft_pixel_to_ray(x, y, &scene->camera);
	// if(i %1 == 0) //tests github
	// {
	// 	double t;
	// 	if (ray.inters_lst)
	// 	{
	// 		if (intersect_sphere(ray_to_pixel(x, y, &scene->camera), *scene->objects, &t) == 0)
	// 		{
	// 			printf("PROBLEM 1 (we intersect not them)\n");
	// 			printf("intersect with our ray ? %d\n", intersect_sphere(ray, *scene->objects, &t));
	// 			return (0x0000FF);
	// 		}
	// 		else if (ft_eq(ray.inters_lst->t, t) == FALSE)
	// 			printf("PROBLEM 2 (wrong t value): t = %f, t1 == %f t2 = %f\n", t, ray.inters_lst->t, ray.inters_lst->next->t);
	// 	}
	// 	else
	// 	{
	// 		if (intersect_sphere(ray_to_pixel(x, y, &scene->camera), *scene->objects, &t) == 1)
	// 		{
	// 			printf("PROBLEM 3 (we dont intersect they do)\n");
	// 			t_ray ray2 = ray_to_pixel(x, y, &scene->camera);
	// 			ft_inters_sphere(scene->objects, &ray2);
	// 			printf("intersect with their ray ? %d\n", ray2.inters_lst != NULL);
	// 			if (ft_eq(ray.origin.x, ray2.origin.x) == FALSE |
	// 				ft_eq(ray.origin.y, ray2.origin.y) == FALSE |
	// 				ft_eq(ray.origin.z, ray2.origin.z) == FALSE)
	// 			{
	// 				ft_tuple_print(ray.origin);
	// 				ft_tuple_print(ray2.origin);
	// 			}
	// 			if (ft_eq(ray.direction.x, ray2.direction.x) == FALSE |
	// 				ft_eq(ray.direction.y, ray2.direction.y) == FALSE |
	// 				ft_eq(ray.direction.z, ray2.direction.z) == FALSE)
	// 			{
	// 				ft_tuple_print(ray.direction);
	// 				ft_tuple_print(ray2.direction);
	// 			}
	// 			return (0x00FF00);
	// 		}
	// 	}
	// }
	// if(i %100 == 0)
	// {
	// 	if (ray.inters_lst)
	// 		printf("LP :	t1 = %f t2 = %f\n", ray.inters_lst->t, ray.inters_lst->next->t);
	// 	else
	// 		printf("LP :	none\n");
	// 	double t;
	// 	if (intersect_sphere(ray_to_pixel(x, y, &scene->camera), *scene->objects, &t) == 1)
	// 		printf("Autre :	t = %f\n\n", t);
	// 	else
	// 		printf("Autre :	none\n\n");
	// }
	ft_inters_sphere(scene->objects, &ray);
	hit = ft_hit(&ray.inters_lst);
	if (hit)
	{
		color = ft_get_color_at_point(
			*hit->object,
			ft_position(ray, hit->t),
			*scene->lights,
			scene->camera.direction);
		ft_free_inters_lst(ray.inters_lst);
		return (ft_color_to_int(color));
		//return(0xFF0000);
	}
	ft_free_inters_lst(ray.inters_lst);
	return (0x000000);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_H][SIZE_V])
{
	size_t	x;
	size_t	y;

	ft_mat_obj(scene->objects);
	x = -1;
	while (++x < SIZE_H)
	{
		y = -1;
		while (++y < SIZE_V)
			canvas[x][y] = ft_get_color_pixel(scene, x, y);
	}
	return (EXIT_SUCCESS);
}
