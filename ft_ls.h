/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:14:36 by prippa            #+#    #+#             */
/*   Updated: 2018/01/21 17:14:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "libft.h"

# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

# define LS_NORMAL		"\x1B[0m"
# define LS_RED			"\x1B[31m"
# define LS_GREEN		"\x1B[32m"
# define LS_YELLOW		"\x1B[33m"
# define LS_BLUE		"\x1B[34m"
# define LS_MAGENTA		"\x1B[35m"
# define LS_CYAN		"\x1B[36m"

# define LS_NAME_SIZE	255
# define LS_FLAG_SIZE	8
# define LS_MODE_SIZE	11

# define R_BIG			0
# define R_MINI			1
# define A_MINI			2
# define L_MINI			3
# define T_MINI			4
# define G_BIG			5
# define V_MINI			6
# define Y_MINI			7

# define LI ls->i
# define LJ ls->j
# define PI pth->i
# define PJ pth->j

typedef struct			s_ls
{
	char				**file_path;
	struct stat			*file_stat;
	int					*width;
	int					i;
	int					j;
}						t_ls;

typedef struct			s_lspath
{
	char				flags[LS_FLAG_SIZE + 1];
	char				**files;
	char				**dirs;
	char				**e_path;
	int					i;
	int					j;
}						t_lspath;

int						*ls_get_width(struct stat *stat_buf, int size);
struct stat				*ls_get_stat(char **path);
int						ls_get_mode(char **line, char *path, mode_t mode);

int						ls_isname_toolong(char *path);
int						ls_isfile(char *path);
int						ls_isdir(char *path);

int						ls_get_args(t_lspath *pth, char **argv);
int						ls_get_flags(t_lspath *pth, char **argv);

void					ls_print_permision_error(char *path);
void					ls_print_dir(char *path, char *flg);
void					ls_print_file(char *path, char *name,
						char *flg, int *width);

void					ls_len_sort(char ***arr);
void					ls_base_sort(char ***arr);
void					ls_time_sort(char ***arr, int i, int j);

int						ls_readdir(t_ls *ls, char *path, char *flg);

void					ls_color(int c);
void					ls_print_total(t_ls *ls);
void					ls_show_link(char *path);

#endif
