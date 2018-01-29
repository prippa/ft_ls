/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:32:35 by prippa            #+#    #+#             */
/*   Updated: 2018/01/27 17:32:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			*ls_get_width(struct stat *stat_buf, int size)
{
	int	*width;
	int	i;

	width = (int *)malloc(sizeof(int) * 4);
	ft_bzero(width, sizeof(int) * 4);
	i = 0;
	while (i < size)
	{
		width[0] = MAX(width[0], ft_nbrlen(stat_buf[i].st_nlink));
		width[1] = MAX(width[1],
		(int)ft_strlen(getpwuid(stat_buf[i].st_uid)->pw_name));
		width[2] = MAX(width[2],
		(int)ft_strlen(getgrgid(stat_buf[i].st_gid)->gr_name));
		width[3] = MAX(width[3], ft_nbrlen(stat_buf[i].st_size));
		i++;
	}
	return (width);
}

struct stat	*ls_get_stat(char **path)
{
	struct stat	*file_stat;
	int			i;
	int			j;

	j = ft_arrlen(path);
	file_stat = (struct stat *)malloc(sizeof(struct stat) * j);
	i = 0;
	while (i < j)
	{
		lstat(path[i], &file_stat[i]);
		i++;
	}
	return (file_stat);
}

void		ls_print_total(t_ls *ls)
{
	long long int t;

	t = 0;
	LI = 0;
	while (ls->file_path[LI])
	{
		t += ls->file_stat[LI].st_blocks;
		LI++;
	}
	ft_printf("total %lld\n", t);
}

void		ls_color(int c)
{
	c %= 7;
	if (c == 0)
		ft_putstr(LS_RED);
	else if (c == 1)
		ft_putstr(LS_YELLOW);
	else if (c == 2)
		ft_putstr(LS_GREEN);
	else if (c == 3)
		ft_putstr(LS_CYAN);
	else if (c == 4)
		ft_putstr(LS_BLUE);
	else if (c == 5)
		ft_putstr(LS_MAGENTA);
	else if (c == 6)
		ft_putstr(LS_NORMAL);
}

void		ls_show_link(char *path)
{
	char buf[LS_NAME_SIZE + 1];

	ft_bzero(buf, LS_NAME_SIZE + 1);
	readlink(path, buf, LS_NAME_SIZE);
	ft_printf(" -> %s", buf);
}
