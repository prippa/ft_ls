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

static void		ls_get_files_from_dir(t_ls *ls, DIR *directory)
{
	struct dirent	*dp;
	int				len;
	int				i;

	len = 0;
	dp = readdir(directory);
	if (dp)
	{
		while (dp)
		{
			dp = readdir(directory);
			len++;
		}
		closedir(directory);
		directory = opendir(ls->path);
		ls->file_name = (char **)malloc(sizeof(char *) * len + 1);
		ls->file_name[len] = NULL;
		i = 0;
		while (i < len)
		{
			ls->file_name[i] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE + 1);
			ls->file_name[i][FILE_NAME_SIZE] = '\0';
			i++;
		}
		i = 0;
		dp = readdir(directory);
		while (dp)
		{
			ft_strcpy(ls->file_name[i], dp->d_name);
			i++;
			dp = readdir(directory);
		}
		closedir(directory);
	}
}

void			ls_show_dir(char *path)
{
	t_ls			ls;
	DIR				*directory;
	int				i;

	if (!(directory = opendir(path)))
		ft_printf("ls: %s: No such file or directory\n", path);
	else
	{
		ls.path = ft_strdup(path);
		ls_get_files_from_dir(&ls, directory);
		ls_base_sort(&ls);
		i = 0;
		while (ls.file_name[i])
		{
			ft_printf("%s\n", ls.file_name[i]);
			i++;
		}
		free(ls.path);
		free(ls.file_name);
	}
}
