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

char    **test_and_format(char **tetri)                     /* en cours */
{
    int     i;
    int     j;
    char    l;
    int     bloc;

    bloc = 0;
    i = 0;
    while ( i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ft_putendl("test");
            if (tetri[i][j] == '#')
            {
                if (!(tetri[i-1][j]))
                    bloc++;
                else if (tetri[i-1][j] == '#')
                    bloc++;
                if (!(tetri[i+1][j]))
                    bloc++;
                else if (tetri[i+1][j] == '#')
                    bloc++;
                if (!(tetri[i][j + 1]))
                    bloc++;
                else if (tetri[i][j + 1] == '#')
                    bloc++;
                if (!(tetri[i][j - 1]))
                    bloc++;
                else if (tetri[i][j - 1] == '#')
                    bloc++;
                if (bloc < 2)
                    return (0);
            }
            bloc = 0;
            j++;
        }
        i++;
    }
    return (tetri);
}

int     get_tetri(const int fd)
{
    char    ***tetris;                                                   /* tetris[nb_tetris][largeur][longueur] / nb_tetris a recup*/
    int     i;
    int     j;
    char    *line;

    if (!(tetris = ft_tab2tabnew(4, 4, 4)))
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
            if(!(tetris[i] = test_and_format(tetris[i])))
                return (0);
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
