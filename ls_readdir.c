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

static void	ls_file_count(t_ls *ls, DIR *directory, struct dirent *dp, char *flg)
{
	int				len;

	len = 0;
	while (dp)
	{
		if (flg[A_MINI] || dp->d_name[0] != '.')
			len++;
		dp = readdir(directory);
	}
	ls->file_name = (char **)malloc(sizeof(char *) * len + 1);
	ls->file_name[len] = NULL;
	LI = 0;
	while (LI < len)
	{
		FNI = (char *)malloc(sizeof(char) * LS_NAME_SIZE + 1);
		ls->file_name[LI][LS_NAME_SIZE] = '\0';
		LI++;
	}
	closedir(directory);
}

int			ls_readdir(t_ls *ls, DIR *directory, char *path, char *flg)
{
	struct dirent	*dp;

	dp = readdir(directory);
	if (!dp)
		return (0);
	ls_file_count(ls, directory, dp, flg);
	directory = opendir(path);
	dp = readdir(directory);
	LI = 0;
	while (dp)
	{
		if (flg[A_MINI] || dp->d_name[0] != '.')
		{
			ft_strcpy(FNI, dp->d_name);
			LI++;
		}
		dp = readdir(directory);
	}
	closedir(directory);
	return (1);
}
