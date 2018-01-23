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

static void		ls_lobi(t_lspath *pth)
{
	PI = 0;
	while (pth->e_path[PI])
	{
		if (ls_isname_toolong(pth->e_path[PI]))
			ft_printf("ls: %s: File name too long\n", pth->e_path[PI]);
		else
			ft_printf("ls: %s: No such file or directory\n", pth->e_path[PI]);
		PI++;
	}
	PI = 0;
	while (pth->files[PI])
		ls_print_file(pth->files[PI++]);
	PI = 0;
	if (pth->files || pth->e_path)
		ft_printf("\n%s:\n", pth->dirs[PI]);
	while (pth->dirs[PI])
	{
		ls_print_dir(pth->dirs[PI]);
		PI++;
		if (pth->dirs[PI])
			ft_printf("\n%s:\n", pth->dirs[PI]);
	}
}

int				main(int argc, char **argv)
{
	t_lspath pth;

	if (argc == 1)
		ls_print_dir(".");
	else
	{
		ls_get_args(&pth, argv + 1);
		ls_lobi(&pth);
	}
	//system("leaks ft_ls");
	return (0);
}
