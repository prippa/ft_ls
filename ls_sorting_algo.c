/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:16:57 by prippa            #+#    #+#             */
/*   Updated: 2018/01/19 12:17:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_get_stat(t_ls *ls)
{
	LJ = ft_arrlen(ls->file_path);
	ls->file_stat = (struct stat *)malloc(sizeof(struct stat) * LJ);
	LI = 0;
	while (LI < LJ)
	{
		stat(ls->file_path[LI], &ls->file_stat[LI]);
		LI++;
	}
}

void	ls_time_sort(t_ls *ls, char *buf, int n, long int tmp)
{
	ls_get_stat(ls);
	n = ft_arrlen(ls->file_path);
	LI = 0;
	while (LI < n)
	{
		LJ = 0;
		while (LJ < (n - 1))
		{
			if ((ls->file_stat[LJ].st_mtime) < (ls->file_stat[LJ + 1].st_mtime))
			{
				tmp = ls->file_stat[LJ].st_mtime;
				ls->file_stat[LJ].st_mtime = ls->file_stat[LJ + 1].st_mtime;
				ls->file_stat[LJ + 1].st_mtime = tmp;
				buf = ft_strdup(ls->file_path[LJ]);
				free(ls->file_path[LJ]);
				ls->file_path[LJ] = ft_strdup(ls->file_path[LJ + 1]);
				free(ls->file_path[LJ + 1]);
				ls->file_path[LJ + 1] = ft_strdup(buf);
				free(buf);
			}
			LJ++;
		}
		LI++;
	}
}

void	ls_base_sort(char ***arr)
{
	int		i;
	int		j;
	int		len;
	char	*buf;

	len = ft_arrlen(*arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
			{
				buf = ft_strdup((*arr)[j]);
				free((*arr)[j]);
				(*arr)[j] = ft_strdup((*arr)[j + 1]);
				free((*arr)[j + 1]);
				(*arr)[j + 1] = ft_strdup(buf);
				free(buf);
			}
			j++;
		}
		i++;
	}
}
