/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_contrast.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 10:56:56 by pacovali      #+#    #+#                 */
/*   Updated: 2019/10/28 10:56:56 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_CONTRAST_H
# define __FT_CONTRAST_H

# define ANSI_COLOR_RESET   "\x1b[0m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_RED     "\x1b[31m"

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_data
{
	int 		src_fd; //source file file-descriptor
	char		*src_name; //source file
	char		*out_name; //output file
	size_t		max; //maximal value in the file (3rd row)
	float		contrast; //check it to be between 0 and 100 on user
	size_t		*src_content;
	size_t		width;
	size_t		height;
	size_t		*out_content;
}				t_data;

int					ft_saveinput(t_data *input_data, int argc, char **argv);
int					ft_errormanagement(int error, t_data *input_data);
int					read_file(t_data *input_data);

#endif
