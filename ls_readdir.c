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

static void	ls_file_count(t_ls *ls, char *flg, char *path)
{
	struct dirent	*dp;
	DIR				*directory;
	int				len;

	len = 0;
	directory = opendir(path);
	dp = readdir(directory);
	while (dp)
	{
		if (flg[A_MINI] || dp->d_name[0] != '.')
			len++;
		dp = readdir(directory);
	}
	closedir(directory);
	ls->file_path = (char **)malloc(sizeof(char *) * len + 1);
	ls->file_path[len] = NULL;
}

int			ls_readdir(t_ls *ls, char *path, char *flg)
{
	struct dirent	*dp;
	DIR				*directory;
	char			*buf;

	directory = opendir(path);
	dp = readdir(directory);
	if (!dp)
	{
		closedir(directory);
		return (0);
	}
	ls_file_count(ls, flg, path);
	buf = ft_strjoin(path, "/");
	ls->i = 0;
	while (dp)
	{
		if (flg[A_MINI] || dp->d_name[0] != '.')
			ls->file_path[ls->i++] = ft_strjoin(buf, dp->d_name);
		dp = readdir(directory);
	}
	closedir(directory);
	free(buf);
	return (1);
}
