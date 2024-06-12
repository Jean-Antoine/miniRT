/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/11 17:50:58 by lpaquatt         ###   ########.fr       */
=======
/*   Updated: 2024/06/11 13:29:58 by jeada-si         ###   ########.fr       */
>>>>>>> f648313e3131de7365f2b65a8ee86133f0bd4fea
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
	printf("freeing\n");
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
	ft_display(canvas);// a changer	
	return (ft_exit(EXIT_SUCCESS, scene));
}

/*test reflection*/
// int	main(int ac, char **av)
// {
// 	t_scene		scene;
// 	t_object	*sphere;
// 	t_vector	v1;
// 	t_vector	n;
// 	t_vector	l;

// 	ft_bzero(&scene, sizeof(scene));
// 	if (ac != 2)
// 		return (ft_error("wrong number of arguments", FALSE));
// 	if (ft_parse(&scene, av[1]))
// 		return (ft_exit(EXIT_FAILURE, scene));
// 	sphere = scene.objects;
<<<<<<< HEAD
// 	ft_mat_sphere(sphere);
// 	v1 = ft_get_normal_at_sp(*sphere, ft_p_set(0, 1, 0));
// 	//ft_tuple_print(v1);
// 	l = ft_v_set(0, -1, -1);
// 	n = ft_v_set(0, 0, 1);
// 	ft_tuple_print(ft_reflect(l, n));
=======
// 	ray = ft_ray(scene.camera.position, scene.camera.direction);
// 	ft_inters_sphere(sphere, ray);
// 	inters = ray->inters_lst;
// 	while (inters)
// 	{
// 		printf("TEST > t = %f\n", inters->t);
// 		inters = inters->next;
// 	}
// 	// inters_lst = NULL;
// 	// ft_new_inters(&inters_lst, sphere, 5);
// 	// ft_new_inters(&inters_lst, sphere, 7);
// 	// ft_new_inters(&inters_lst, sphere, -3);
// 	// ft_new_inters(&inters_lst, sphere, 2);
// 	// ft_new_inters(&inters_lst, sphere, -10);
// 	hit = ft_hit(&ray->inters_lst);
// 	if (hit)
// 		printf("TEST > Hit : t = %f\n", hit->t);
>>>>>>> f648313e3131de7365f2b65a8ee86133f0bd4fea
// }


// int main(void)
// {
// 	ft_mat_print(
// 		ft_mat_prod(
// 			ft_translation(0, 1, 2),
// 			ft_scaling(2, 2, 2)
// 		)
// 	);
// 	printf("\n");
// 	ft_mat_print(
// 		ft_mat_prod(			
// 			ft_scaling(2, 2, 2), 
// 		)
// 	);
// }