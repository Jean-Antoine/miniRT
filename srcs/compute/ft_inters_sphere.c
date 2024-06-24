/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:24:51 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/07 10:58:31 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static int	ft_is_inters(t_ray ray, double *t1, double *t2)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_vector	sphere_to_ray;

	sphere_to_ray = ft_p_to_v(ft_point(0, 0, 0), ray.origin);
	a = ft_v_dot_prod(ray.direction, ray.direction);
	b = 2.0 * ft_v_dot_prod(ray.direction, sphere_to_ray);
	c = ft_v_dot_prod(sphere_to_ray, sphere_to_ray) - 1.0;
	discr = b * b - 4.0 * a * c;
	if (discr < 0)
		return (EXIT_FAILURE);
	*t1 = (-b - sqrt(discr)) / (2.0 * a);
	*t2 = (-b + sqrt(discr)) / (2.0 * a);
	return (EXIT_SUCCESS);
}

int	ft_inters_sphere(t_object *sphere, t_ray *ray)
{
	t_ray		ray2;
	double		t1;
	double		t2;

	ray2 = ft_transform(*ray, sphere->transform);
	if (ft_is_inters(ray2, &t1, &t2))
		return (EXIT_FAILURE);
	return (
		ft_new_inters(&ray->inters_lst, sphere, t1) ||
		ft_new_inters(&ray->inters_lst, sphere, t2));
}

/*tests github*/
// typedef struct	s_qparams
// {
// 	double	a;
// 	double	b;
// 	double	c;
// }				t_qparams;

// void		swap_doubles(double *a, double *b)
// {
// 	double buffer;

// 	buffer = *a;
// 	*a = *b;
// 	*b = buffer;
// }

// t_qparams	new_qparams(double a, double b, double c)
// {
// 	t_qparams params;

// 	params.a = a;
// 	params.b = b;
// 	params.c = c;
// 	return (params);
// }

// int			solve_quadratic(t_qparams params, double *x0, double *x1)
// {
// 	double discr;
// 	double q;

// 	discr = pow(params.b, 2) - 4 * params.a * params.c;
// 	if (discr < 0)
// 		return (0);
// 	else if (discr == 0)
// 	{
// 		*x0 = -0.5 * params.b / params.a;
// 		*x1 = -0.5 * params.b / params.a;
// 	}
// 	else
// 	{
// 		if (params.b > 0)
// 			q = -1 * (params.b + sqrt(discr)) / 2;
// 		else
// 			q = -1 * (params.b - sqrt(discr)) / 2;
// 		*x0 = q / params.a;
// 		*x1 = params.c / q;
// 	}
// 	if (*x0 > *x1)
// 		swap_doubles(x0, x1);
// 	return (1);
// }

// double	dot_product(t_vector a, t_vector b)
// {
// 	double sum;

// 	sum = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
// 	return (sum);
// }

// int			get_roots(double *t0, double *t1, t_ray ray, t_object sphere)
// {
// 	t_vector	l;
// 	double	a;
// 	double	b;
// 	double	c;

// 	l = ft_p_to_v(sphere.position, ray.origin);
// 	a = dot_product(ray.direction, ray.direction);
// 	b = 2.0 * dot_product(ray.direction, l);
// 	c = dot_product(l, l) - (sphere.diameter * sphere.diameter);
// 	if (solve_quadratic(new_qparams(a, b, c), t0, t1) == 0)
// 		return (0);
// 	return (1);
// }

// int			intersect_sphere(t_ray ray, t_object sphere, double *t)
// {
// 	double t0;
// 	double t1;

// 	if (get_roots(&t0, &t1, ray, sphere) == 0)
// 		return (0);
// 	if (t0 < 0)
// 	{
// 		t0 = t1;
// 		if (t0 < 0)
// 			return (0);
// 	}
// 	*t = t0;
// 	return (1);
// }



// int main(void)
// {
// 	double	t1;
// 	double	t2;
//  t_ray	ray;

// 	ray = ft_ray(ft_point(0, 0, 5), ft_vector(0, 0, 1));
// 	if (!ft_is_inters(ray, &t1, &t2))
// 		printf("values are %f and %f", t1, t2);
// }

// int main(void)
// {
// 	t_object sp;
// 	t_ray		ray;

// 	sp.type = sphere;
// 	sp.transform = ft_mat_inv(ft_scaling(2, 2, 2));
// 	ray = ft_ray(ft_point(0, 0, -5), ft_vector(0, 0, 1));
// 	ft_inters_sphere(&sp, &ray);
// 	printf("%f and %f\n", ray.inters_lst->t, ray.inters_lst->next->t);

// 	sp.transform = ft_mat_inv(ft_scaling(5, 0, 0));
// 	ray = ft_ray(ft_point(0, 0, -5), ft_vector(0, 0, 1));
// 	ft_inters_sphere(&sp, &ray);
// 	printf("%f and %f\n", ray.inters_lst->t, ray.inters_lst->next->t);
// }