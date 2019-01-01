#include "fillit.h"

            /* in progress */

char     **is_free_and_place(char **res, char **tetri, int lig, int col)            /* /!\ */
{
    int i;
    int j;
    int cpt;
    int tmp;

    tmp = col;
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
 /*   if (!tetri[i])
        i--;            */
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
        col = tmp;
        j = 0;
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

        if (res[i][j] == '.')
        {
            while (tetris[t])
            {
                if (placed[t] != '1' && (res = is_free_and_place(res, tetris[t], i, j)))  /* /!\ */
                {
                        placed[t] = '1';
                        t++;
                        int k = 0;                              /* debug */
                        while (res[k] != NULL)
                        {
                            ft_putendl(res[k]);
                            k++;
                        }
                        ft_putchar('\n');                          /* fin degub */
                        break ;
                }
                t++;
            }
        }
        if (i <= j)
            i++;
        else
            j++;
    }
    i = 0;
    while (i < nbtetri)
    {
        if (placed[i] != '1')
            return (NULL);
        i++;
    }
    ft_putendl("AHHHHH");
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
    siz = 4;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);
    while (!(res = compute(res, tetris, nbtetri)))
	{
		ft_putendl("tyui");
		siz++;
		ft_2tabdel(res, siz);
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }

    ft_putendl("tt");                           /* debug */

    return (1);
}
