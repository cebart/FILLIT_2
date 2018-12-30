#include "fillit.h"

            /* in progress */

char     **is_free_and_place(char **res, char **tetri, int lig, int col)            /* /!\ */
{
    int i;
    int j;
    int cpt;
    ft_putendl("test");
    i = 0;
    cpt = 0;
    while (tetri[i])
    {
        j = 0;
        while (tetri[i][j] && tetri[i][j] == '.')
        {
            j++;
        }
        if (!tetri[i][j])
            j--;
        if (tetri[i][j] != '.')
            break ;
        i++;
    }
    if (!tetri[i])
        i--;
    while (res[lig] && tetri[i])
    {
        while (res[lig][col] && tetri[i][j])
        {
            if (tetri[i][j] != '.' && res[lig][col] != '.')
                return (NULL);
            else if (tetri[i][j] != '.')
            {
                res[lig][col] = tetri[i][j];
                cpt++;
            }
            if (tetri[i][j] != '.')
                col++;
            j++;
        }
        lig++;
        i++;
        j = 0;
        col = 0;
    }
    if (cpt != 4)
        return (NULL);
    return (res);
}

char    **compute(char **res, char ***tetris, int nbtetri)
{
    int     t;
    int     i;
    int     j;
    char    *placed;

    i = 0;
    j = 0;
    t = 0;
    placed = ft_strnew(nbtetri);
    while (i < nbtetri)
    {
        placed[i] = '0';
        i++;
    }
    i = 0;
    while (res[i][j])
    {
        i = 0;
        while (res[i])                                      /* /!\ */
        {
            if (res[i][j] && res[i][j] == '.')
            {
                while (tetris[t])
                {
                    if (placed[t] != '1')
                    {
                        if ((res = is_free_and_place(res, tetris[t], i, j)))            /* /!\ */
                        {
                            placed[t] = '1';
                            t++;
                            break ;
                        }
                    }
                    t++;
                }
                ft_putendl("test1");
            }
            ft_putendl("test2");
            i++;
        }
        ft_putendl("test");
        j++;
    }

    ft_putendl(placed);                 /* debug */

    i = 0;
    while (i < nbtetri)
    {
        if (placed[i] != '1')
            return (0);
        i++;
    }

    i = 0;                              /* debug */
	while (res[i] != NULL)
	{
        ft_putendl(res[i]);
        i++;
	}                                    /* fin debug */

    return (res);
}

int     solve(int siz, char ***tetris)
{
    char    **res;
    int     nbtetri;

    nbtetri = siz;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);
    res = compute(res, tetris, nbtetri);                    /* debug */
    while (!(res = compute(res, tetris, nbtetri)))
	{
		ft_putendl("tyui");
		siz++;
		ft_2tabdel(res, siz);
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }

ft_putendl("tt");
    int i = 0;
    while (res)                                 /* debug */
	{
        ft_putendl(res[i]);
        i++;
	}                                           /* fin debug */

    return (1);
}
