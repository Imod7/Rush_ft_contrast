/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_contrast.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 11:34:03 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/01 11:34:06 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

int					main(int argc, char **argv)
{
	t_data			*input_data;
	t_lines			*file_lines;
	int				result;

	input_data = ft_memalloc(sizeof(t_data));
	file_lines = ft_memalloc(sizeof(t_lines));
	ft_clearproperties(input_data);
	if (argc < 7 || argc > 7)
		return (ft_errormanagement(1, input_data));
	else
	{
		if (ft_saveinput(input_data, argc, argv) == -1)
			return (-1);
		printf(ANSI_COLOR_GREEN"Saved Image Properties - \
		Our struct is filled \n");
		printf("input data name : %s \n", input_data->src_name);
		printf("contrast : %f \n", input_data->contrast);
		printf("output filename : %s \n", input_data->out_name);
		printf("width : %zu \n", input_data->width);
		printf("height : %zu \n", input_data->height);
		printf("max : %zu \n\n"ANSI_COLOR_RESET, input_data->max);
	}
	result = read_file(input_data);
	if (result == -1)
		return (-1);
	ft_applycontrast(input_data, result, file_lines);
	ft_savenewimage(input_data, file_lines);
	free(input_data);
	return (0);
}
