/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 16:54:52 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/02 16:54:57 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

void				ft_clearproperties(t_data *input_data)
{
	input_data->src_name = "";
	input_data->contrast = 0;
	input_data->out_name = "";
	input_data->width = 0;
	input_data->height = 0;
	input_data->max = 0;
}

int					ft_isawhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int					ft_skipchars(char *s, int index)
{
	while (ft_isawhitespace(s[index]) == 1)
		index++;
	if (s[index] == '#')
	{
		index++;
		while (ft_isawhitespace(s[index]) == 0)
			index++;
		return (index);
	}
	else
		return (index);
}

int					read_file(t_data *input_data)
{
	int				bytes_read;
	char			buf[1000];
	size_t			i;
	int				first_chunk;

	input_data->src_fd = open(input_data->src_name, O_RDONLY);
	if (input_data->src_fd < 0)
		return (ft_errormanagement(4, input_data));
	bytes_read = read(input_data->src_fd, buf, 1000);
	if (bytes_read == -1)
		return (ft_errormanagement(5, input_data));
	// printf("bytes_read = \n %s \n\n", buf);
	i = 0;
	first_chunk = 0;
	while (i < 10)
	{
		if ((ft_isawhitespace(buf[i]) == 0) && (first_chunk == 0))
			i++;
		else
		{
			first_chunk = 1;
			i = ft_skipchars(buf, i);
			// printf(" i = %zu, char = %c \n", i, buf[i]);
			input_data->width = ft_atoi(&buf[i]);
			i += ft_strlen(ft_itoa(input_data->width)) + 1;
			i = ft_skipchars(buf, i);
			// printf(" i = %zu, char = %c \n", i, buf[i]);
			input_data->height = ft_atoi(&buf[i]);
			i += ft_strlen(ft_itoa(input_data->height)) + 1;
			i = ft_skipchars(buf, i);
			// printf(" i = %zu, char = %c \n", i, buf[i]);
			input_data->max = ft_atoi(&buf[i]);
			i += ft_strlen(ft_itoa(input_data->max)) + 1;
			// i = ft_skipchars(buf, i);
			// printf("Arrived where IMAGE starts %zu => %c \n", i, buf[i]);
		}
	}
	close(input_data->src_fd);
	return (i);
}
