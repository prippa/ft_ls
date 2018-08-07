/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_big_s_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:55:47 by prippa            #+#    #+#             */
/*   Updated: 2018/08/07 14:55:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_sort(char ***arr, int index)
{
	char	*buf;

	buf = ft_strdup((*arr)[index]);
	free((*arr)[index]);
	(*arr)[index] = ft_strdup((*arr)[index + 1]);
	free((*arr)[index + 1]);
	(*arr)[index + 1] = ft_strdup(buf);
	free(buf);
}

static void	ls_big_s_sort_algo(char ***arr, struct stat	*file_stat, int j)
{
	intmax_t	tmp;

	tmp = file_stat[j].st_size;
	file_stat[j].st_size = file_stat[j + 1].st_size;
	file_stat[j + 1].st_size = tmp;
	ls_sort(arr, j);
}

void		ls_big_s_sort(char ***arr)
{
	int			len;
	int			i;
	int			j;
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
			if (file_stat[j].st_size < file_stat[j + 1].st_size)
				ls_big_s_sort_algo(arr, file_stat, j);
			else if (file_stat[j].st_size == file_stat[j + 1].st_size)
				if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
					ls_big_s_sort_algo(arr, file_stat, j);
			j++;
		}
		i++;
	}
	free(file_stat);
}
