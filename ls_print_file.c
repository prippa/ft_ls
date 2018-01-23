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

static void	ls_file_type(struct stat file_stat, char *path)
{
	ft_printf((file_stat.st_mode & S_IFDIR) ? "d" : "-");
	ft_printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(listxattr(path, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
	ft_printf("\n");
}

int			ls_print_file(char *path)
{
	struct stat file_stat;

	if (stat(path, &file_stat) < 0)
		return (0);
	ft_printf("%s\n", path);
	return (1);
}
