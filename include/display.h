/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:00:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/30 13:16:14 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "mlx.h"
# define SIZE_X 800
# define SIZE_Y 450

typedef struct s_mlx
{
	void	*conn;
	void	*win;
	void	*img;
	char	*addr;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
}	t_mlx;

void	ft_display(int canvas[SIZE_X][SIZE_Y], int scene_y);

#endif