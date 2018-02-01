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
	struct timespec	tmp;

	tmp = file_stat[j].st_mtimespec;
	file_stat[j].st_mtimespec = file_stat[j + 1].st_mtimespec;
	file_stat[j + 1].st_mtimespec = tmp;
	ls_sort(arr, j);
}

static void	ls_time_sort_if(char ***arr, struct stat *file_stat, int j)
{
	if ((file_stat[j].st_mtimespec.tv_sec)
		< (file_stat[j + 1].st_mtimespec.tv_sec))
	{
		ls_time_sort_algo(arr, file_stat, j);
	}
	else if (file_stat[j].st_mtimespec.tv_sec
		== file_stat[j + 1].st_mtimespec.tv_sec
		&& file_stat[j].st_mtimespec.tv_nsec
		== file_stat[j + 1].st_mtimespec.tv_nsec)
	{
		if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
			ls_time_sort_algo(arr, file_stat, j);
	}
	else if (file_stat[j].st_mtimespec.tv_sec
		== file_stat[j + 1].st_mtimespec.tv_sec
		&& file_stat[j].st_mtimespec.tv_nsec
		< file_stat[j + 1].st_mtimespec.tv_nsec)
	{
		ls_time_sort_algo(arr, file_stat, j);
	}
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
			ls_time_sort_if(arr, file_stat, j);
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

	len = ft_arrlen(*arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
				ls_sort(arr, j);
			j++;
		}
		i++;
	}
}

void		ls_len_sort(char ***arr)
{
	int		i;
	int		j;
	int		len;
	size_t	size;
	size_t	size1;

	len = ft_arrlen(*arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			size = ft_strlen((*arr)[j]);
			size1 = ft_strlen((*arr)[j + 1]);
			if (size > size1)
				ls_sort(arr, j);
			else if (size == size1)
				if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
					ls_sort(arr, j);
			j++;
		}
		i++;
	}
}
