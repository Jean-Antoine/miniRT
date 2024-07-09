/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:35:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 14:27:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "display.h"

/*
	material.diffuse between 0 and 1
	material.specular between 0 and 1
	material.shininess between 10 and 200
	material.pattern is a boolean
	material.texture is a t_img with a valid path, if given path is "none" then 
	there is no texture
*/

static int	ft_is_material(char **tab)
{
	if (ft_tabsize(tab) != 5)
		return (FALSE);
	if (!ft_is_float(tab[0]) || !ft_is_float(tab[1]) || !ft_is_float(tab[2])
		|| !ft_is_numeric(tab[3]))
		return (FALSE);
	if (ft_atof(tab[0]) < 0 || ft_atof(tab[0]) > 1)
		return (FALSE);
	if (ft_atof(tab[1]) < 0 || ft_atof(tab[1]) > 1)
		return (FALSE);
	if (ft_atof(tab[2]) < 10 || ft_atof(tab[2]) > 200)
		return (FALSE);
	if (ft_atoi(tab[3]) != 0 && ft_atoi(tab[3]) != 1)
		return (FALSE);
	return (TRUE);
}

int	ft_get_img_from_path(t_img *img, char *path)
{
	void	*mlx;

	img->path = path;
	mlx = mlx_init();
	if (!mlx)
		return (ft_error("mlx_init", TRUE));
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img_ptr)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (ft_error("mlx_xpm_file_to_image", TRUE));
	}
	img->img_pixels_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	img->img_buff = ft_calloc(img->width * img->height,
			img->bits_per_pixel / 8);
	if (!img->img_buff)
		return (EXIT_FAILURE);
	ft_memcpy(img->img_buff, img->img_pixels_ptr, img->width * img->height
		* img->bits_per_pixel / 8);
	mlx_destroy_image(mlx, img->img_ptr);
	mlx_destroy_display(mlx);
	free(mlx);
	return (EXIT_SUCCESS);
}

int	ft_set_material(t_material *material, char *arg)
{
	char	**args;

	args = ft_split(arg, ',');
	if (!args)
		return (ft_error("ft_split", TRUE));
	if (ft_is_material(args) == FALSE)
	{
		ft_free_tab((void **)args);
		return (ft_error("wrong material format", FALSE));
	}
	material->diffuse = ft_atof(args[0]);
	material->specular = ft_atof(args[1]);
	material->shininess = ft_atof(args[2]);
	material->pattern = ft_atoi(args[3]);
	if (ft_strcmp(args[4], "none")
		&& ft_get_img_from_path(&material->texture, args[4]))
	{
		ft_free_tab((void **)args);
		return (EXIT_FAILURE);
	}
	ft_free_tab((void **)args);
	return (EXIT_SUCCESS);
}
