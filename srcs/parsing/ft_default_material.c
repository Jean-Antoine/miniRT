/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_material.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:54:28 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 16:59:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_material	ft_default_material(void)
{
	t_material	material;

	ft_bzero(&material, sizeof(t_material));
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200;
	material.pattern = FALSE;
	ft_bzero(&material.texture, sizeof(t_img));
	return (material);
}
