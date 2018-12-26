#include "fillit.h"


char        ***ft_tab2tabnew(int nbtab, int nbl, int nbc)
{
    char    ***tab;
	int     i;

	i = 0;
	if (!(tab = (char ***)ft_memalloc(sizeof(char **) * (nbtab + 1))))
        return (0);
	while (i < nbtab)
	 {
        tab[i] = ft_2tabnew(nbl, nbc);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char        **ft_2tabnew(int nbl, int nbc)
{
    char    **tab;
	int     i;

    i = 0;
    if (!nbl || !nbc)
        return (NULL);
    if (!(tab = (char **)malloc(sizeof(char *) * (nbl + 1))))
         return (0);
    while(i < nbl)
    {
        tab[i] = (ft_strnew(nbc + 1));
        i++;
    }
    tab[i] = '\0';
	return (tab);
}

int test_tetri(char **tetri)                     /* en cours  /!\ PB si le tetri se lit de droite a gauche ; ..## \n .##. /!\*/
{
    int     i;
    int     j;
    int     cpt;
    char    **tmp;

    tmp = ft_2tabnew(4, 4);
    i = 0;
    while (i < 4)
    {
        strcpy(tmp[i], tetri[i]);
        i++;
    }
    i = 0;
    cpt = 0;
    while ( i < 4 && cpt < 3)
    {
        j = 0;
        while (j < 4 && cpt < 3)
        {
            if (tmp[i][j] == '#')
            {
                cpt++;
                if ((i != 0 && tmp[i-1][j] != '.') || (i != 3 && tmp[i+1][j] != '.') || (j != 3 && tmp[i][j + 1] != '.') || (j != 0 && tmp[i][j - 1] != '.'))
                    tmp[i][j] = '.';
                else
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

char    **format_tetri(char **tetri, int c)
{
    int     i;
    int     j;
    char    bloc;

    bloc = 'A';
    i = 0;
    while ( i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (tetri[i][j] == '#')
                tetri[i][j] = bloc + c;
            j++;
        }
        i++;
    }
    return (tetri);
}

int     get_tetri(const int fd, int nbtetris)
{
    char    ***tetris;                                                   /* tetris[nb_tetris][largeur][longueur] */
    int     i;
    int     j;
    char    *line;

    if (!(tetris = ft_tab2tabnew(nbtetris, 4, 4)))
        return (0);
    line = ft_strnew(4);
    i = 0;
    while (tetris[i])
    {
        j = 0;
        while (j < 4)
        {
            get_next_line(fd, &line);
            tetris[i][j] = line;
            j++;
        }
        i++;
        get_next_line(fd, &line);
    }
    i = 0;
	while (tetris[i] != NULL)
	{
            if(!test_tetri(tetris[i]))
                return (0);
            tetris[i] = format_tetri(tetris[i], i);
            i++;
	}

    i = 0;                              /* debug */
	while (tetris[i] != NULL)
	{
        j = 0;
        while (j < 4)
        {
            ft_putendl(tetris[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
	}                                           /* fin debug */

    return (1);
}
