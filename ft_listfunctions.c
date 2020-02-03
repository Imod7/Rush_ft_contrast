/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listfunctions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 19:05:54 by dsaripap      #+#    #+#                 */
/*   Updated: 2020/02/02 19:05:58 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

// t_lines		*ft_lines_newnode(int content)
// {
// 	t_lines	*newnode;

// 	newnode = malloc(sizeof(t_lines));
// 	if (newnode == NULL)
// 		return (NULL);
// 	ft_printf("Num = %d Size : %d \n", content, sizeof(content));
// 	newnode->returned_line = content;
// 	newnode->next = NULL;
// 	return (newnode);
// }

void		ft_lines_addend(t_lines **lst, t_lines *new)
{
	t_lines	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void		ft_print_lines(t_lines *lst)
{
	t_lines	*temp;
	int		len;

	temp = lst;
	len = 0;
	if (temp == NULL)
		;
	while (temp != NULL)
	{
		len++;
		printf("%s \n", temp->returned_line);
		temp = temp->next;
	}
	// printf(ANSI_COLOR_YELLOW"Length of the list = %d \n"ANSI_COLOR_RESET, len);
}

int			ft_lines_length(t_lines *lst)
{
	t_lines *temp;
	int		len;

	temp = lst;
	len = 0;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
