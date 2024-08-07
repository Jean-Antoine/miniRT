/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:23 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 16:59:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define INVALID_MSG "Invalid data: "
# include "libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "matrix.h"
# define TRUE 1
# define FALSE 0
# define NORMALIZE_VECTOR 1

typedef int			t_bool;

typedef struct s_img
{
	char		*path;
	void		*img_ptr;
	char		*img_pixels_ptr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	char		*img_buff;
}	t_img;

typedef struct s_material
{
	t_color			color;
	double			diffuse;
	double			specular;
	double			shininess;
	t_bool			pattern;
	t_img			texture;
}	t_material;

typedef enum e_object_type
{
	plane,
	sphere,
	cylinder,
	cone
}	t_object_type;

typedef struct s_object
{
	t_object_type	type;
	t_point			position;
	double			diameter;
	double			height;
	t_vector		direction;
	t_material		material;
	t_mat			transform;
	struct s_object	*next;
}	t_object;

typedef struct s_light
{
	t_point			position;
	double			brightness_ratio;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_camera
{
	t_point			position;
	t_vector		direction;
	double			fov;
	double			half_width;
	double			half_height;
	double			pixel_size;
	t_mat			view_inv;
}	t_camera;

typedef struct s_scene
{
	double			ambient_brightness;
	t_color			ambient_color;
	t_camera		camera;
	t_light			*lights;
	t_object		*objects;
}	t_scene;

size_t		ft_tabsize(char **tab);
int			ft_error(char *str, int use_errno);
int			ft_open_file(char *file_name);
int			ft_parse(t_scene *scene, char *file);
int			ft_parse_line(char *line, t_scene *scene);
int			ft_parse_object(char **args, t_object **dest);
int			ft_parse_light(char **args, t_scene *scene);
int			ft_parse_camera(char **args, t_camera *dest);

int			ft_set_point(t_point *dest, char *str);
int			ft_set_vector(t_vector *dest, char *str);
int			ft_set_scalar(double *dest, char *str);
int			ft_set_color(t_color *color, char *str);
int			ft_set_material(t_material *material, char *arg);
t_material	ft_default_material(void);

int			ft_is_numeric(char *str);
int			ft_is_float(char *str);
int			ft_is_triplet(char **tab);
int			ft_is_normalized(t_vector vector);

void		ft_free_scene(t_scene scene);

#endif