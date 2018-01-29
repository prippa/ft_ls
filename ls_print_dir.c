/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:47:31 by prippa            #+#    #+#             */
/*   Updated: 2018/01/18 15:47:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_rev_output(t_ls *ls, char *flg)
{
	LI = ft_arrlen(ls->file_path);
	while (--LI >= 0)
	{
		if (flg[G_BIG])
			ls_color(LI);
		ls_print_file(ls->file_path[LI],
		(ft_strrchr(ls->file_path[LI], '/') + 1), flg, ls->width);
	}
	if (flg[G_BIG])
		ft_putstr(LS_NORMAL);
}

static void	ls_output(t_ls *ls, char *flg)
{
	if (flg[L_MINI])
	{
		if (ls->file_stat)
			free(ls->file_stat);
		ls->file_stat = ls_get_stat(ls->file_path);
		ls->width = ls_get_width(ls->file_stat, ft_arrlen(ls->file_path));
		ls_print_total(ls);
	}
	if (flg[R_MINI])
	{
		ls_rev_output(ls, flg);
		return ;
	}
	LI = 0;
	while (ls->file_path[LI])
	{
		if (flg[G_BIG])
			ls_color(LI);
		ls_print_file(ls->file_path[LI],
		(ft_strrchr(ls->file_path[LI], '/') + 1), flg, ls->width);
		LI++;
	}
	if (flg[G_BIG])
		ft_putstr(LS_NORMAL);
}

static void	ls_rev_bigr_flag(t_ls *ls, char *flg)
{
	LI = ft_arrlen(ls->file_path);
	while (--LI >= 0)
	{
		if ((ls_isdir(ls->file_path[LI])
			&& ft_strcmp((ft_strrchr(ls->file_path[LI], '/') + 1), ".")
			&& ft_strcmp((ft_strrchr(ls->file_path[LI], '/') + 1), "..")))
		{
			ft_printf("\n%s:\n", ls->file_path[LI]);
			ls_print_dir(ls->file_path[LI], flg);
		}
	}
}

static void	ls_bigr_flag(t_ls *ls, char *flg)
{
	if (flg[R_MINI])
	{
		ls_rev_bigr_flag(ls, flg);
		return ;
	}
	LI = 0;
	while (ls->file_path[LI])
	{
		if ((ls_isdir(ls->file_path[LI])
			&& ft_strcmp((ft_strrchr(ls->file_path[LI], '/') + 1), ".")
			&& ft_strcmp((ft_strrchr(ls->file_path[LI], '/') + 1), "..")))
		{
			ft_printf("\n%s:\n", ls->file_path[LI]);
			ls_print_dir(ls->file_path[LI], flg);
		}
		LI++;
	}
}

void		ls_print_dir(char *path, char *flg)
{
	t_ls			ls;

	ls.file_path = NULL;
	ls.file_stat = NULL;
	ls.width = NULL;
	if (!(ls_readdir(&ls, path, flg)))
		return ;
	if (flg[T_MINI])
		ls_time_sort(&ls, NULL, 0, 0);
	else
		ls_base_sort(&ls.file_path);
	ls_output(&ls, flg);
	if (flg[R_BIG])
		ls_bigr_flag(&ls, flg);
	if (ls.file_stat)
		free(ls.file_stat);
	if (ls.width)
		free(ls.width);
	ft_arr_free(&ls.file_path);
}
