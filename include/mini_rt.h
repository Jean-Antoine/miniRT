/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:10:31 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/29 12:16:52 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "struct.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libraries.h"
# include "operations.h"
# include "parsing.h"
# define SIZE_X 800
# define SIZE_Y 450
# define TRUE 1
# define FALSE 0
# define OK 1
# define KO 0
# define CONN 0
# define WIN 1
# define EXIT_CODE 2

 // a deplacer
void	ft_display(int canvas[SIZE_X][SIZE_Y], int scene_y);

#endif