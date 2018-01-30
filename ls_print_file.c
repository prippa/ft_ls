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

static void	ls_print_time(struct stat stat_buf)
{
	char	*t;
	time_t	local_time;

	local_time = time(0);
	local_time -= stat_buf.st_mtime;
	t = ft_strdup(ctime(&stat_buf.st_mtime));
	if ((local_time * (((local_time) > 0) * 2 - 1)) > 15770000)
		ft_printf(" %3.3s %2.2s  %4.4s", &t[4], &t[8], &t[20]);
	else
		ft_printf(" %3.3s %2.2s %5.5s", &t[4], &t[8], &t[11]);
	free(t);
}

static void	ls_l(char *path, char *name, int *width)
{
	struct stat		stat_buf;
	char			*mode;

	lstat(path, &stat_buf);
	ls_get_mode(&mode, path, stat_buf.st_mode);
	ft_printf("%s %*d %*s  %*s  %*jd",
	mode,
	width[0], stat_buf.st_nlink,
	width[1], getpwuid(stat_buf.st_uid)->pw_name,
	width[2], getgrgid(stat_buf.st_gid)->gr_name,
	width[3], (intmax_t)stat_buf.st_size);
	ls_print_time(stat_buf);
	ft_printf(" %s", name);
	if (S_ISLNK(stat_buf.st_mode))
		ls_show_link(path);
	write(1, "\n", 1);
	free(mode);
}

void		ls_print_file(char *path, char *name, char *flg, int *width)
{
	if (flg[L_MINI])
		ls_l(path, name, width);
	else
		ft_printf("%s\n", name);
}
