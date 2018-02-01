/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:33:49 by prippa            #+#    #+#             */
/*   Updated: 2018/01/22 16:33:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_mem(t_lspath *pth, int f_len, int d_len, int e_len)
{
	pth->files = (char **)malloc(sizeof(char *) * f_len + 1);
	pth->files[f_len] = NULL;
	pth->dirs = (char **)malloc(sizeof(char *) * d_len + 1);
	pth->dirs[d_len] = NULL;
	pth->e_path = (char **)malloc(sizeof(char *) * e_len + 1);
	pth->e_path[e_len] = NULL;
}

static void		ls_get_mem(t_lspath *pth, char **argv)
{
	int f_len;
	int d_len;
	int e_len;

	if (argv[PI] && !ft_strcmp(argv[PI], "--"))
		PI++;
	f_len = 0;
	d_len = 0;
	e_len = 0;
	PJ = PI;
	while (argv[PJ])
	{
		if (ls_isdir(argv[PJ]) || errno == 13)
			d_len++;
		else if (ls_isfile(argv[PJ]))
			f_len++;
		else
			e_len++;
		PJ++;
	}
	ls_mem(pth, f_len, d_len, e_len);
}

static void		ls_get_path(t_lspath *pth, char **argv)
{
	int f_len;
	int d_len;
	int e_len;

	ls_get_mem(pth, argv);
	f_len = 0;
	d_len = 0;
	e_len = 0;
	while (argv[PI])
	{
		if ((ls_isdir(argv[PI]) || errno == 13))
			pth->dirs[d_len++] = ft_strdup(argv[PI]);
		else if (ls_isfile(argv[PI]))
			pth->files[f_len++] = ft_strdup(argv[PI]);
		else
			pth->e_path[e_len++] = ft_strdup(argv[PI]);
		PI++;
	}
}

static void		ls_sort_pth(t_lspath *pth)
{
	if (pth->flags[T_MINI])
	{
		ls_time_sort(&pth->files, 0, 0);
		ls_time_sort(&pth->dirs, 0, 0);
	}
	else if (pth->flags[Y_MINI])
	{
		ls_len_sort(&pth->files);
		ls_len_sort(&pth->dirs);
	}
	else if (pth->flags[S_BIG])
	{
		ls_big_s_sort(&pth->files);
		ls_big_s_sort(&pth->dirs);
	}
	else
	{
		ls_base_sort(&pth->files);
		ls_base_sort(&pth->dirs);
	}
	ls_base_sort(&pth->e_path);
}

int				ls_get_args(t_lspath *pth, char **argv)
{
	pth->files = NULL;
	pth->dirs = NULL;
	pth->e_path = NULL;
	if ((PJ = ls_get_flags(pth, argv)) > 0)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(PJ, 2);
		ft_putstr_fd("\nusage: ls [-AGRSalrtvy1] [file ...]\n", 2);
		return (0);
	}
	ls_get_path(pth, argv);
	ls_sort_pth(pth);
	return (1);
}
