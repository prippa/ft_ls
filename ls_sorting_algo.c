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

void	ls_base_sort(t_ls *ls)
{
	char	*buf;
	int		len;
	int		i;
	int		j;

	len = ft_arrlen(ls->file_name);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp(ls->file_name[j], ls->file_name[j + 1]) > 0)
			{
				ft_strcpy(buf, ls->file_name[j]);
				ft_strcpy(ls->file_name[j], ls->file_name[j + 1]);
				ft_strcpy(ls->file_name[j + 1], buf);
			}
			j++;
		}
		i++;
	}
}
