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

static void	ls_l(char *path, char *name, int *width)
{
	struct stat		stat_buf;
	char			*mode;
	char			*time;

	lstat(path, &stat_buf);
	ls_get_mode(&mode, path, stat_buf.st_mode);
	time = ft_strdup(ctime(&stat_buf.st_mtime));
	ft_printf("%s %*d %*s  %*s  %*jd %3.3s %2.2s %5.5s %s",
	mode,
	width[0], stat_buf.st_nlink,
	width[1], getpwuid(stat_buf.st_uid)->pw_name,
	width[2], getgrgid(stat_buf.st_gid)->gr_name,
	width[3], (intmax_t)stat_buf.st_size,
	&time[4], &time[8], &time[11],
	name);
	if (S_ISLNK(stat_buf.st_mode))
		ls_show_link(path);
	write(1, "\n", 1);
	free(mode);
	free(time);
}

void		ls_print_file(char *path, char *name, char *flg, int *width)
{
	if (flg[L_MINI])
		ls_l(path, name, width);
	else
		ft_printf("%s\n", name);
}
