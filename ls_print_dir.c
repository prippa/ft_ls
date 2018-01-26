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

void		ls_bigr_flag(t_ls *ls, char *flg, char *path)
{
	char *new_path;

	LI = 0;
	while (FNI)
	{
		new_path = ft_strjoin(path, FNI);
		if ((ls_isdir(new_path) && ft_strcmp(FNI, ".") && ft_strcmp(FNI, "..")))
		{
			ft_printf("\n%s:\n", new_path);
			ls_print_dir(new_path, flg);
		}
		free(new_path);
		LI++;
	}
	free(path);
}

int			ls_print_dir(char *path, char *flg)
{
	t_ls			ls;
	DIR				*directory;

	directory = opendir(path);
	if (!(ls_readdir(&ls, directory, path, flg)))
		return (0);
	// if (flg[T_MINI])
	// 	ls_time_sort(&ls.file_name);
	// else
		ls_base_sort(&ls.file_name);
	ls.i = 0;
	while (ls.file_name[ls.i])
	{
		ft_printf("%s\n", ls.file_name[ls.i]);
		ls.i++;
	}
	if (flg[R_BIG])
		ls_bigr_flag(&ls, flg, ft_strjoin(path, "/"));
	ft_arr_free(&ls.file_name);
	return (1);
}
