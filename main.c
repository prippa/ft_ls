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
	struct stat 	arg1;
	struct stat 	arg2;
	char			*time1;
	char			*time2;

	stat(argv[1], &arg1);
	stat(argv[2], &arg2);
	time1 = ft_strdup(ctime(&arg1.st_mtime));
	time2 = ft_strdup(ctime(&arg2.st_mtime));

	//printf("%s%s", time1, time2);
	if (ft_strcmp(time1, time2) > 0)
		printf("%s\n", time1);
	// t_lspath pth;

	// ft_bzero(pth.flags, LS_FLAG_SIZE);
	// if (argc == 1)
	// 	ls_print_dir(".", pth.flags);
	// else
	// {
	// 	ls_get_args(&pth, argv + 1);
	// 	if (!pth.e_path[0] && !pth.files[0] && !pth.dirs[0])
	// 		ls_print_dir(".", pth.flags);
	// 	else
	// 		ls_lobi(&pth);
	// 	ft_arr_free(&pth.files);
	// 	ft_arr_free(&pth.dirs);
	// 	ft_arr_free(&pth.e_path);
	// }
	//system("leaks ft_ls");
	return (0);
}
