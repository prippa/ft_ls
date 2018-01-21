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
	char	buf[FILE_NAME_SIZE + 1];
	int		len;

	len = ft_arrlen(ls->file_name);
	I = 0;
	while (I < len)
	{
		J = 0;
		while (J < len - 1)
		{
			if (ft_strcmp(ls->file_name[J], ls->file_name[J + 1]) > 0)
			{
				ft_strcpy(buf, ls->file_name[J]);
				ft_strcpy(ls->file_name[J], ls->file_name[J + 1]);
				ft_strcpy(ls->file_name[J + 1], buf);
			}
			J++;
		}
		I++;
	}
}
