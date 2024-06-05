/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/05 15:24:10 by lpaquatt         ###   ########.fr       */
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

// int	main(int ac, char **av)
// {
// 	t_scene	scene;
// 	int		canvas[SIZE_X][SIZE_Y];

// 	ft_bzero(&scene, sizeof(scene));
// 	if (ac != 2)
// 		return (ft_error("wrong number of arguments", FALSE));
// 	if (ft_parse(&scene, av[1]))
// 		return (ft_exit(EXIT_FAILURE, scene));
// 	if (ft_compute(&scene, canvas))
// 		return (ft_exit(EXIT_FAILURE, scene));
// 	ft_free_scene(scene);
// 	ft_display(canvas, scene.size_y);
// 	return (ft_exit(EXIT_SUCCESS, scene));
// }

/* test intersect*/
int	main(int ac, char **av)
{
	t_scene	scene;
	t_inters 	*inters_lst;
	t_ray 		*ray;
	t_object	*sphere;
	t_inters	*inters;

	ft_bzero(&scene, sizeof(scene));
	if (ac != 2)
		return (ft_error("wrong number of arguments", FALSE));
	if (ft_parse(&scene, av[1]))
		return (ft_exit(EXIT_FAILURE, scene));
	sphere = scene.objects;
	ray = ft_create_ray(scene.camera.position, scene.camera.direction);
	inters_lst = NULL;
	ft_intersect_sphere(sphere, ray);
	inters = ray->inters_lst;
	while (inters)
	{
		printf("TEST > t = %f\n", inters->t);
		inters = inters->next;
	}
}

// int	main(void)
// {
// 	t_mat	A;
// 	t_mat	B;

// 	A.col = 3;
// 	A.row = 3;
// 	A.mat[0][0] = -2; A.mat[0][1] = -8; A.mat[0][2] = 3; A.mat[0][3] = 5;
// 	A.mat[1][0] = -3; A.mat[1][1] = 1; A.mat[1][2] = 7; A.mat[1][3] = 3;
// 	A.mat[2][0] = 1; A.mat[2][1] = 2; A.mat[2][2] = -9; A.mat[2][3] = 6;
// 	A.mat[3][0] = -6; A.mat[3][1] = 7; A.mat[3][2] = 7; A.mat[3][3] = -9;
// 	printf("A is:\n");
// 	if (!ft_is_inv(A))
// 		return (1);
// 	ft_mat_print(A);
// 	printf("A-1 is:\n");
// 	ft_mat_print(ft_mat_inv(A));
// 	B.col = 3;
// 	B.row = 3;
// 	B.mat[0][0] = 1; B.mat[0][1] = 0; B.mat[0][2] = 0;
// 	B.mat[1][0] = 0; B.mat[1][1] = 0; B.mat[1][2] = 0;
// 	B.mat[2][0] = 0; B.mat[2][1] = 0; B.mat[2][2] = 1;
// 	printf("B is:\n");
// 	ft_mat_print(B);
// 	printf("test B.A.A_I is:\n");
// 	ft_mat_print(ft_mat_prod(ft_mat_prod(B, A), ft_mat_inv(A)));
// 	// printf("determinant is %f\n", ft_mat_discr(A));
// 	// ft_mat_print(ft_submatrix(A, 1, 2));
// }