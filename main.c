/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:54:06 by prippa            #+#    #+#             */
/*   Updated: 2018/01/08 17:54:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_out_file_l(t_lspath *pth)
{
	int			*width;
	struct stat	*stat_buf;

	if (!pth->files[0])
		return ;
	stat_buf = ls_get_stat(pth->files);
	width = ls_get_width(stat_buf, ft_arrlen(pth->files));
	if (pth->flags[G_BIG])
		ft_putstr(LS_CYAN);
	if (pth->flags[R_MINI])
	{
		PI = ft_arrlen(pth->files);
		while (--PI >= 0)
			ls_print_file(pth->files[PI], pth->files[PI], pth->flags, width);
	}
	else
	{
		PI = 0;
		while (pth->files[PI])
			ls_print_file(pth->files[PI], pth->files[PI++], pth->flags, width);
	}
	if (pth->flags[G_BIG])
		ft_putstr(LS_NORMAL);
	free(width);
	free(stat_buf);
}

static void		ls_out_file(t_lspath *pth)
{
	if (pth->flags[V_MINI])
		ft_printf("count ---[%u]---\n", ft_arrlen(pth->files));
	if (pth->flags[L_MINI])
	{
		ls_out_file_l(pth);
		return ;
	}
	if (pth->flags[G_BIG])
		ft_putstr(LS_CYAN);
	if (pth->flags[R_MINI])
	{
		PI = ft_arrlen(pth->files);
		while (--PI >= 0)
			ls_print_file(pth->files[PI], pth->files[PI], pth->flags, NULL);
	}
	else
	{
		PI = 0;
		while (pth->files[PI])
			ls_print_file(pth->files[PI], pth->files[PI++], pth->flags, NULL);
	}
	if (pth->flags[G_BIG])
		ft_putstr(LS_NORMAL);
}

static void		ls_out_error(t_lspath *pth)
{
	PI = 0;
	while (pth->e_path[PI])
	{
		if (ls_isname_toolong(pth->e_path[PI]))
		{
			if (pth->flags[G_BIG])
				ft_putstr(LS_RED);
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(pth->e_path[PI], 2);
			ft_putstr_fd(": File name too long\n", 2);
		}
		else
		{
			if (pth->flags[G_BIG])
				ft_putstr(LS_YELLOW);
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(pth->e_path[PI], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		PI++;
	}
	if (pth->flags[G_BIG])
		ft_putstr(LS_NORMAL);
}

static void		ls_lobi(t_lspath *pth)
{
	ls_out_error(pth);
	ls_out_file(pth);
	PI = 0;
	if (pth->dirs[0] && pth->files[0])
		write(1, "\n", 1);
	if (pth->dirs[0] && (pth->files[0] || pth->e_path[0] || pth->dirs[1]))
		ft_printf("%s:\n", pth->dirs[0]);
	while (pth->dirs[PI])
	{
		ls_isdir(pth->dirs[PI]);
		if (errno == 13)
			ls_print_permision_error(pth->dirs[PI]);
		else
			ls_print_dir(pth->dirs[PI], pth->flags);
		PI++;
		if (pth->dirs[PI])
			ft_printf("\n%s:\n", pth->dirs[PI]);
	}
}

int				main(int argc, char **argv)
{
	t_lspath pth;

	ft_bzero(pth.flags, LS_FLAG_SIZE + 1);
	if (argc == 1)
		ls_print_dir(".", pth.flags);
	else
	{
		if (!(ls_get_args(&pth, argv + 1)))
			return (1);
		if (!pth.e_path[0] && !pth.files[0] && !pth.dirs[0])
			ls_print_dir(".", pth.flags);
		else
			ls_lobi(&pth);
		ft_arr_free(&pth.files);
		ft_arr_free(&pth.dirs);
		ft_arr_free(&pth.e_path);
	}
	return (0);
}
