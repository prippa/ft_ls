/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:24:39 by prippa            #+#    #+#             */
/*   Updated: 2018/01/22 11:24:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static void	ls_file_type(struct stat file_stat, char *path)
// {
	
// }

int			ls_print_file(char *path)
{
	struct stat file_stat;

	stat(path, &file_stat);
	ft_printf("%s\n", path);
	return (1);
}
