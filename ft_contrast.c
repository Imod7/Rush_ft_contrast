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

	input_data = ft_memalloc(sizeof(t_data));
	if (argc < 7 || argc >7)
		return (ft_errormanagement(1, input_data));
	else
	{
		if (ft_saveinput(input_data, argc, argv) == -1)
			return (-1);
	}
	if (read_file(input_data) == -1)
		return (-1);
	printf(ANSI_COLOR_GREEN"\nOur struct is filled \n");
	printf("input data name : %s \n", input_data->src_name);
	printf("contrast : %f \n", input_data->contrast);
	printf("output filename : %s \n", input_data->out_name);
	printf("width : %zu \n", input_data->width);
	printf("height : %zu \n", input_data->height);
	printf("max : %zu \n"ANSI_COLOR_RESET, input_data->max);
	free(input_data->src_name);
	return (0);
}
