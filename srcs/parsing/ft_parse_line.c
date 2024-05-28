/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/28 12:15:21 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_args_to_scene(char **args, t_scene *scene)
{
	int	exit_code;
	
	if (!args || !args[0])
		return (EXIT_SUCCESS);
	exit_code = ft_parse_light(args, &scene->lights)
		* ft_parse_object(args, &scene->objects);
	if (exit_code == 4)
		return (ft_error("unknown identifier", FALSE));
	return (exit_code != 0);
}

int	ft_parse_line(char *line, t_scene *scene)
{
	char	**args;
	int		exit_code;

	if (!line)
		return (EXIT_FAILURE);
	if (!ft_strcmp(line, "\n"))
		return (EXIT_SUCCESS);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	args = ft_split(line, ' ');
	if (!args)
		return (ft_error("ft_split", TRUE));
	exit_code = ft_args_to_scene(args, scene);
	ft_free_tab((void **) args);
	return (exit_code);
}
