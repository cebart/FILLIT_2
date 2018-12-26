#ifndef FILLIT_H
# define FILLIT_H
#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int     check_file(const int fd, int *nbtetris);
int     get_tetri(const int fd, int nbtetris);
char    **ft_2tabnew(int nbl, int nbc);
char    ***ft_tab2tabnew(int nbtab, int nbl, int nbc);
int     test_tetri(char **tetri);
char    **format_tetri(char **tetri, int c);
char    **ft_2tabcpy(char **tab);


#endif
