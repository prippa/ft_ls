/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:47:31 by prippa            #+#    #+#             */
/*   Updated: 2018/01/18 15:47:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_print_dir(char *path)
{
	t_ls			ls;
	DIR				*directory;

	if (!(directory = opendir(path)))
		return (0);
	if (!(ls_readdir(&ls, directory, path)))
		return (0);
	ls_base_sort(&ls.file_name);
	ls.i = 0;
	while (ls.file_name[ls.i])
	{
		ft_printf("%s\n", ls.file_name[ls.i]);
		ls.i++;
	}
	ft_arr_free(&ls.file_name);
	return (1);
}
