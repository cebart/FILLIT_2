#include "fillit.h"

            /* in progress / pb de destruction de blocs qd faux ?*/

int     is_free_and_place(char **res, char **tetri, int lig, int col)
{
    int i;
    int j;
    int cpt;
    int tmp;
    char **tab;

    tab = ft_2tabcpy(res);
    tmp = col;
    i = 0;
    cpt = 0;
    while (res[lig] && tetri[i])
    {
        j = 0;
        while (res[lig][col] && tetri[i][j])
        {
            if (tetri[i][j] != '.' && res[lig][col] != '.')
                return (0);
            else if (tetri[i][j] != '.')
            {
                res[lig][col] = tetri[i][j];
                cpt++;
            }
            col++;
            j++;
        }
        lig++;
        i++;
        col = tmp;
    }
    if (cpt != 4)
        return (0);
    else
        res = ft_2tabcpy(tab);
    return (1);
}

int     compute(char **res, char ***tetris, int nbtetri)
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
        placed[i++] = '0';
    i = 0;
	while (res[i] != '\0')
	{
		j = 0;
		while (res[i][j] != '\0')
		{
            t = 0;
            while (tetris[t])
            {
                if (placed[t] != '1' && is_free_and_place(res, tetris[t], i, j))
                {
                    placed[t] = '1';
                    t++;
                    break ;
                }
                t++;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < nbtetri)
    {
        if (placed[i++] != '1')
            return (0);
    }
    return (1);
}

int     solve(int siz, char ***tetris)
{
    char    **res;
    int     nbtetri;

    nbtetri = siz;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);
    while (!compute(res, tetris, nbtetri))                          /* si ! reset de res */
	{
		siz++;
		ft_2tabdel(res, siz);
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }
                            int k = 0;                              /* debug */
                            while (res[k] != NULL)
                            {
                                ft_putendl(res[k]);
                                k++;
                            }                                   /* fin degub */
    return (1);
}
