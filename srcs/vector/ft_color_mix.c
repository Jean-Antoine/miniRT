/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:35:18 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/24 11:36:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_color	ft_color_mix(t_color color1, t_color color2)
{
	color1.x *= color2.x;
	color1.y *= color2.y;
	color1.z *= color2.z;
	return (color1);
}
