/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_saveargs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 16:54:07 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/02 16:54:10 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

int					ft_errormanagement(int error, t_data *input_data)
{
	if (error == 1)
	{
		printf("\nPlease enter the correct number of arguments as shown in the \
		usage below \n");
		printf(ANSI_COLOR_RED"usage: ft_contrast -f [image_name.pgm] -c \
		[contrast_level_number] -o [output_filename] \n"ANSI_COLOR_RESET);
	}
	else if (error == 2)
	{
		printf("\nPlease enter the correct type of flags as shown in the \
		usage below \n");
		printf(ANSI_COLOR_RED"usage: ft_contrast -f [image_name.pgm] -c \
		[contrast_level_number] -o [output_filename] \n"ANSI_COLOR_RESET);
	}
	else if (error == 3)
	{
		printf("\nWrong contrast level \n");
		printf(ANSI_COLOR_RED"Please enter a valid contrast level (number \
		between 0 and 100) \n"ANSI_COLOR_RESET);
	}
	else if (error == 4)
		printf("\nError when opening the file\n");
	else if (error == 5)
		printf("\nError when trying to read the file\n");
	free(input_data->src_name);
	return (-1);
}

int					ft_saveinput(t_data *input_data, int argc, char **argv)
{
	int				i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_strcmp(argv[i], "-f") == 0)
		{
			i++;
			input_data->src_name = ft_strdup(argv[i]);
		}
		else if (ft_strcmp(argv[i], "-c") == 0)
		{
			i++;
			input_data->contrast = (float)(ft_atoi(argv[i])) / 100;
			if (input_data->contrast < 0 || input_data->contrast > 1)
				return (ft_errormanagement(3, input_data));
		}
		else if (ft_strcmp(argv[i], "-o") == 0)
		{
			i++;
			input_data->out_name = ft_strdup(argv[i]);
		}
		else
			return (ft_errormanagement(2, input_data));
		i++;
	}
	return (0);
}
