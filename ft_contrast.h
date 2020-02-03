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
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_CYAN    "\x1b[36m"

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_data
{
	int 			src_fd; //source file file-descriptor
	char			*src_name; //source file
	char			*out_name; //output file
	size_t			max; //maximal value in the file (3rd row)
	float			contrast; //check it to be between 0 and 100 on user
	size_t			*src_content;
	size_t			width;
	size_t			height;
	size_t			*out_content;
}					t_data;

typedef struct		s_lines
{
	char			*returned_line;
	char			**pixel_array;
	int				*pixel_original;
	int				*pixel_result;
	size_t			number_of_pixels;
	struct s_lines	*next;
}					t_lines;

int				ft_saveinput(t_data *input_data, int argc, char **argv);
int				ft_errormanagement(int error, t_data *input_data);
int				read_file(t_data *input_data);
void			ft_clearproperties(t_data *input_data);
int				ft_applycontrast(t_data *input_data, size_t index, \
								t_lines *file_lines);

/*
** List Functions
*/

void		ft_lines_addend(t_lines **lst, t_lines *new);
void		ft_print_lines(t_lines *lst);
int			ft_savenewimage(t_data *input_data, t_lines *file_lines);

#endif
