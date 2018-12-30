#include "fillit.h"

            /* in progress */

char     **is_free_and_place(char **res, char **tetri, int lig, int col)     /* /!\ */
{
    int i;
    int j;
    int cpt;

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

char    **compute(char **res, char ***tetris, int nbtetri)               /* alterner ligne puis colonne */
{
    int     t;
    int     i;
    int     j;
    char    **tmp;
    char     *placed;

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
    tmp = ft_2tabcpy(res);
    while (tmp[i][j])
    {
        i = 0;
        while (tmp[i])
        {
            if (tmp[i][j] == '.')
            {
                while (tetris[t])
                {
                    if (placed[t] != '1')
                    {
                        if ((tmp = is_free_and_place(tmp, tetris[t], i, j)))
                        {
                            placed[t] = '1';
                            t++;
                            break ;
                            ft_putendl("da grosse daronne ?");
                        }
                    }
                    t++;
                }
            }
            i++;
        }
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
	while (tmp[i] != NULL)
	{
        ft_putendl(tmp[i]);
        i++;
	}
	                                            /* fin debug */
    return (res);
}



int     solve(int siz, char ***tetris)
{
    char    **res;
    int     nbtetri;

    nbtetri = siz;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);

    while (!(res = compute(res, tetris, nbtetri)))
	{
		siz++;
		ft_2tabdel(res, siz);
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }


    int i = 0;
    while (res)                                 /* debug */
	{
        ft_putendl(res[i]);
        i++;
	}                                           /* fin debug */

    return (1);
}
