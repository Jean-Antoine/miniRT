/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 11:05:00 by jeada-si         ###   ########.fr       */
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

	O = ft_p_create(0, 0, 0);
	A = ft_p_create(1, 0, 0);
	V = ft_p_to_v(O, A);
	printf("norm V = %f\n", ft_v_norm(V));
	W = ft_v_create(0, 1, 0);
	B = ft_p_translate(A, W);
	printf("B = (%f, %f, %f)\n", B.x, B.y, B.z);
	W = ft_v_add(V, W);
	printf("W = (%f, %f, %f)\n", W.x, W.y, W.z);
	W = ft_v_scalar_prod(2, W);
	printf("W = (%f, %f, %f)\n", W.x, W.y, W.z);
	W = ft_v_normalize(W);
	printf("W = (%f, %f, %f)\n", W.x, W.y, W.z);
	printf("norm W = %f\n", ft_v_norm(W));
	printf("dot product V . W = %f\n", ft_v_dot_prod(V, W));
	R = ft_v_cross_prod(V, W);
	printf("cross product V x W = (%f, %f, %f)\n", R.x, R.y, R.z);
	R = ft_v_cross_prod(W, V);
	printf("cross product W x V = (%f, %f, %f)\n", R.x, R.y, R.z);
	return (EXIT_SUCCESS);
}
