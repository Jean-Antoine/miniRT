/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:26:41 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/07 15:00:25 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_exit(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->conn, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->conn, mlx->win);
	if (mlx->conn)
	{
		mlx_destroy_display(mlx->conn);
		free(mlx->conn);
	}
	exit (EXIT_SUCCESS);
}

static void	ft_draw(t_mlx *mlx, int canvas[SIZE_X][SIZE_Y], int size_x)
{
	char	*offset;
	int		x;
	int		y;

	x = -1;
	while (++x < size_x)
	{
		y = -1;
		while (++y < SIZE_Y)
		{
			offset = mlx->addr + (y * mlx->line_length + x
					* (mlx->bits_per_pixel / 8));
			*(unsigned int *) offset = canvas[x][y];
		}
	}
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img, 0, 0);
}

static int	ft_key_hook(int keycode, void *param)
{
	if (keycode == XK_Escape)
		ft_exit(param);
	return (0);
}

void	ft_display(int canvas[SIZE_X][SIZE_Y], int size_x)
{
	t_mlx	mlx;

	ft_bzero(&mlx, sizeof(mlx));
	mlx.conn = mlx_init();
	if (mlx.conn)
		mlx.win = mlx_new_window(mlx.conn, size_x, SIZE_Y, "miniRT");
	if (mlx.win)
		mlx.img = mlx_new_image(mlx.conn, size_x, SIZE_Y);
	if (mlx.img)
		mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
				&mlx.line_length, &mlx.endian);
	if (!mlx.conn || !mlx.win || !mlx.img || !mlx.img)
	{
		ft_putstr_fd("Error\nCould not "
			"start mlx display\n", STDERR_FILENO);
		ft_exit(&mlx);
	}
	ft_draw(&mlx, canvas, size_x);
	mlx_hook(mlx.win, 17, 0, ft_exit, &mlx);
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	mlx_loop(mlx.conn);
}
