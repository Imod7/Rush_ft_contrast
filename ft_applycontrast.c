/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_changepixels.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 17:56:56 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/02 17:57:01 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

t_lines		*ft_changebrightness(t_data *input_data, t_lines *fileline)
{
	size_t	i;

	i = 0;
	while (fileline->pixel_array[i] != '\0')
	{
		(fileline->pixel_original)[i] = ft_atoi((fileline->pixel_array)[i]);
		(fileline->pixel_result)[i] = (fileline->pixel_original)[i] * \
		(input_data->contrast);
		i++;
	}
	return (fileline);
}

void		ft_changecontrast(t_data *input_data, t_lines *fileline)
{
	size_t	i;

	i = 0;
	while ((fileline->pixel_array)[i] != '\0')
	{
		(fileline->pixel_original)[i] = ft_atoi((fileline->pixel_array)[i]);
		// printf(ANSI_COLOR_CYAN"original = %d - ", \
		// (fileline->pixel_original)[m]);
		(fileline->pixel_result)[i] = (259 * (input_data->contrast + \
		input_data->max)) / (input_data->max * (259 - \
		input_data->contrast));
		printf("intermediate pixel = %d \n", (fileline->pixel_result)[i]);
		(fileline->pixel_result)[i] = (int)((fileline->pixel_original)[i] * \
		(input_data->contrast - 128) + 128);
		// printf(ANSI_COLOR_CYAN"result = %d \n"ANSI_COLOR_RESET, \
		// (fileline->pixel_result)[m]);
		i++;
	}
}

int			ft_applycontrast(t_data *input_data, size_t index, \
							t_lines *file_lines)
{
	int		j;
	char	**tmp;
	size_t	number_count;
	t_lines	*fileline;

	input_data->src_fd = open(input_data->src_name, O_RDONLY);
	lseek(input_data->src_fd, index, SEEK_SET);
	printf(ANSI_COLOR_YELLOW"Applying Brightness...\n"ANSI_COLOR_RESET);
	j = 1;
	while (j > 0)
	{
		fileline = ft_memalloc(sizeof(t_lines));
		j = get_next_line(input_data->src_fd, &(fileline->returned_line));
		if (j == 0)
			break ;
		if (input_data->src_fd < 0)
			return (0);
		fileline->pixel_array = ft_strsplit(fileline->returned_line, ' ');
		tmp = fileline->pixel_array;
		// number of words/string numbers in the line
		number_count = 0;
		while (tmp[number_count])
			number_count++;
		fileline->number_of_pixels = number_count;
		fileline->pixel_original = (int *)malloc(sizeof(int) * \
		(number_count + 1));
		fileline->pixel_result = (int*)malloc(sizeof(int) * (number_count + 1));
		if (fileline->pixel_original == NULL)
			return (0);
		fileline = ft_changebrightness(input_data, fileline);
		ft_lines_addend(&file_lines, fileline);
		// printf(ANSI_COLOR_GREEN"Printing one node / one line \n"ANSI_COLOR_RESET);
		// ft_print_lines(fileline);
		// printf("\n j = %d", j);
	}
	// printf(ANSI_COLOR_YELLOW"\nPrinting linked list of lines \n"ANSI_COLOR_RESET);
	// ft_print_lines(file_lines);
	return (0);
}

void		ft_saveproperties(t_data *input_data, int fd)
{
	char	*str;
	int		str_len;

	write(fd, "P2\n", 3);
	str = ft_itoa(input_data->width);
	str_len = ft_strlen(str);
	write(fd, str, str_len);
	write(fd, "\n", 1);
	str = ft_itoa(input_data->height);
	str_len = ft_strlen(str);
	write(fd, str, str_len);
	write(fd, "\n", 1);
	str = ft_itoa(input_data->max);
	str_len = ft_strlen(str);
	write(fd, str, str_len);
	write(fd, "\n", 1);
}

int			ft_savenewimage(t_data *input_data, t_lines *file_lines)
{
	t_lines	*temp;
	int		fd;
	char	*str;
	int		str_len;
	size_t	i;

	temp = file_lines;
	fd = open(input_data->out_name, O_CREAT | O_WRONLY | O_TRUNC);
	if (fd < 0)
		return (-1);
	ft_saveproperties(input_data, fd);
	while (temp != NULL)
	{
		i = 0;
		while (i < temp->number_of_pixels)
		{
			str = ft_itoa((temp->pixel_result)[i]);
			str_len = ft_strlen(str);
			write(fd, str, str_len);
			write(fd, " ", 1);
			i++;
		}
		temp = temp->next;
	}
	printf(ANSI_COLOR_GREEN"New image created! \n"ANSI_COLOR_RESET);
	return (0);
}
