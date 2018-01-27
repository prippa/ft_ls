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
		ls_print_file(pth->files[PI], pth->files[PI++]);
	PI = 0;
	if (pth->dirs[0] && (pth->files[0] || pth->e_path[0]))
		write(1, "\n", 1);
	if (pth->dirs[0] && (pth->files[0] || pth->e_path[0] || pth->dirs[1]))
		ft_printf("%s:\n", pth->dirs[PI]);
	while (pth->dirs[PI])
	{
		ls_print_dir(pth->dirs[PI], pth->flags);
		PI++;
		if (pth->dirs[PI])
			ft_printf("\n%s:\n", pth->dirs[PI]);
	}
}

int				main(int argc, char **argv)
{
	t_lspath pth;

	ft_bzero(pth.flags, LS_FLAG_SIZE);
	if (argc == 1)
		ls_print_dir(".", pth.flags);
	else
	{
		if (!(ls_get_args(&pth, argv + 1)))
			return (0);
		if (!pth.e_path[0] && !pth.files[0] && !pth.dirs[0])
			ls_print_dir(".", pth.flags);
		else
			ls_lobi(&pth);
		ft_arr_free(&pth.files);
		ft_arr_free(&pth.dirs);
		ft_arr_free(&pth.e_path);
	}
	//system("leaks ft_ls");
	return (1);
}
