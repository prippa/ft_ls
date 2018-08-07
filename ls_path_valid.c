/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_path_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:39:06 by prippa            #+#    #+#             */
/*   Updated: 2018/01/23 11:39:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_isname_toolong(char *path)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(path, '/');
	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > LS_NAME_SIZE)
		{
			ft_arr_free(&arr);
			return (1);
		}
		i++;
	}
	ft_arr_free(&arr);
	return (0);
}

int		ls_isfile(char *path)
{
	struct stat file_stat;

	if (lstat(path, &file_stat) < 0)
		return (0);
	return (1);
}

int		ls_isdir(char *path)
{
	DIR *directory;

	if (!(directory = opendir(path)))
		return (0);
	closedir(directory);
	return (1);
}

void	ls_print_permision_error(char *path)
{
	if (ft_strrchr(path, '/'))
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(ft_strrchr(path, '/') + 1, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}
