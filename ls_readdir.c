/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:42:41 by prippa            #+#    #+#             */
/*   Updated: 2018/01/21 13:42:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_file_count(t_ls *ls, DIR *directory, struct dirent *dp)
{
	int				len;

	len = 0;
	while (dp)
	{
		if (dp->d_name[0] != '.')
			len++;
		dp = readdir(directory);
	}
	ls->file_name = (char **)malloc(sizeof(char *) * len + 1);
	ls->file_name[len] = NULL;
	I = 0;
	while (I < len)
	{
		FNI = (char *)malloc(sizeof(char) * FILE_NAME_SIZE + 1);
		ls->file_name[I][FILE_NAME_SIZE] = '\0';
		I++;
	}
	closedir(directory);
}

void		ls_readdir(t_ls *ls, DIR *directory, char *path)
{
	struct dirent	*dp;

	dp = readdir(directory);
	if (!dp)
		return ;
	ls_file_count(ls, directory, dp);
	directory = opendir(path);
	dp = readdir(directory);
	I = 0;
	while (dp)
	{
		if (dp->d_name[0] != '.')
		{
			ft_strcpy(FNI, dp->d_name);
			I++;
		}
		dp = readdir(directory);
	}
	closedir(directory);
}
