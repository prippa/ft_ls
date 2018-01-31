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

static void	ls_time_sort_algo(char ***arr, struct stat	*file_stat, int j)
{
	char	*buf;
	long	tmp;

	tmp = file_stat[j].st_mtimespec.tv_sec;
	file_stat[j].st_mtimespec.tv_sec = file_stat[j + 1].st_mtimespec.tv_sec;
	file_stat[j + 1].st_mtimespec.tv_sec = tmp;
	buf = ft_strdup((*arr)[j]);
	free((*arr)[j]);
	(*arr)[j] = ft_strdup((*arr)[j + 1]);
	free((*arr)[j + 1]);
	(*arr)[j + 1] = ft_strdup(buf);
	free(buf);
}

void		ls_time_sort(char ***arr, int i, int j)
{
	int			len;
	struct stat	*file_stat;

	len = ft_arrlen(*arr);
	if (len < 2)
		return ;
	file_stat = ls_get_stat(*arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1))
		{
			if ((file_stat[j].st_mtimespec.tv_sec)
				< (file_stat[j + 1].st_mtimespec.tv_sec))
				ls_time_sort_algo(&(*arr), file_stat, j);
			else if ((file_stat[j].st_mtimespec.tv_sec)
				== (file_stat[j + 1].st_mtimespec.tv_sec))
				if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
					ls_time_sort_algo(&(*arr), file_stat, j);
			j++;
		}
		i++;
	}
	free(file_stat);
}

void		ls_base_sort(char ***arr)
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
