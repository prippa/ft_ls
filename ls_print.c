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

void			ls_print(char *path)
{
	t_ls			ls;
	DIR				*directory;

	if (!(directory = opendir(path)))
		ft_printf("ls: %s: No such file or directory\n", path);
	else
	{
		ls_readdir(&ls, directory, path);
		ls_base_sort(&ls);
		ls.i = 0;
		while (ls.file_name[ls.i])
		{
			ft_printf("%s\n", ls.file_name[ls.i]);
			ls.i++;
		}
		ls_free(&ls);
	}
}
