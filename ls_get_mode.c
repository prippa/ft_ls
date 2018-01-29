/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:23:31 by prippa            #+#    #+#             */
/*   Updated: 2018/01/24 17:23:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_mode(char **buf, mode_t mode)
{
	int i;

	i = 1;
	(*buf)[i++] = *((mode & S_IRUSR) ? "r" : "-");
	(*buf)[i++] = *((mode & S_IWUSR) ? "w" : "-");
	if (mode & S_ISUID)
		(*buf)[i++] = *((mode & S_IXUSR) ? "s" : "S");
	else
		(*buf)[i++] = *((mode & S_IXUSR) ? "x" : "-");
	(*buf)[i++] = *((mode & S_IRGRP) ? "r" : "-");
	(*buf)[i++] = *((mode & S_IWGRP) ? "w" : "-");
	if (mode & S_ISGID)
		(*buf)[i++] = *((mode & S_IXGRP) ? "s" : "S");
	else
		(*buf)[i++] = *((mode & S_IXGRP) ? "x" : "-");
	(*buf)[i++] = *((mode & S_IROTH) ? "r" : "-");
	(*buf)[i++] = *((mode & S_IWOTH) ? "w" : "-");
	if (mode & S_ISVTX)
		(*buf)[i++] = *((mode & S_IXOTH) ? "t" : "T");
	else
		(*buf)[i++] = *((mode & S_IXOTH) ? "x" : "-");
}

static int	ls_type(char **buf, mode_t mode)
{
	int c;

	c = (mode & S_IFMT);
	if (c == S_IFDIR)
		(*buf)[0] = 'd';
	else if (c == S_IFCHR)
	{
		(*buf)[0] = 'c';
		return (1);
	}
	else if (c == S_IFBLK)
	{
		(*buf)[0] = 'b';
		return (1);
	}
	else if (c == S_IFLNK)
		(*buf)[0] = 'l';
	else if (c == S_IFSOCK)
		(*buf)[0] = 's';
	else if (c == S_IFIFO)
		(*buf)[0] = 'f';
	else
		(*buf)[0] = '-';
	return (0);
}

int			ls_get_mode(char **line, char *path, mode_t mode)
{
	int		flag;

	*line = ft_strnew(LS_MODE_SIZE);
	flag = ls_type(&(*line), mode);
	ls_mode(&(*line), mode);
	(*line)[10] = *(listxattr(path, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
	return (flag);
}
