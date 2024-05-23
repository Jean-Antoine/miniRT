/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:12:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

//test vector operations
int	main(void)
{
	t_point	O;
	t_point	A;
	t_point B;
	t_vector V;
	t_vector W;
	t_vector R;

	O = ft_create_point(0, 0, 0);
	A = ft_create_point(1, 0, 0);
	V = ft_create_vector_from_points(O, A);
	printf("norm V = %f\n", ft_get_vector_norm(V));
	W = ft_create_vector(0, 1, 0);
	B = ft_translate_point(A, W);
	printf("B = (%f, %f, %f)\n", B.x, B.y, B.z);
	W = ft_add_vectors(V, W);
	printf("W = (%f, %f, %f)\n", W.x, W.y, W.z);
	W = ft_multiply_vector_by_num(2, W);
	printf("W = (%f, %f, %f)\n", W.x, W.y, W.z);
	W = ft_normalize_vector(W);
	printf("W = (%f, %f, %f)\n", W.x, W.y, W.z);
	printf("norm W = %f\n", ft_get_vector_norm(W));
	printf("dot product V . W = %f\n", ft_dot_product_vectors(V, W));
	R = ft_cross_product_vectors(V, W);
	printf("cross product V x W = (%f, %f, %f)\n", R.x, R.y, R.z);
	R = ft_cross_product_vectors(W, V);
	printf("cross product W x V = (%f, %f, %f)\n", R.x, R.y, R.z);
	return (EXIT_SUCCESS);
}
