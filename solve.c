#include "fillit.h"

int     is_free(char **tab, int lig, int col, char **tetri, int *cpt)
{
    int i;
    int j;

    i = 0;
    while (tab[lig] && tetri[i])
    {
        j = 0;
        while (tab[lig][col] && tetri[i][j])
        {
            if (tetri[i][j] != '.' && tab[lig][col] != '.')
                return (0);
            else if (tetri[i][j] != '.')
            {
                tab[lig][col] = tetri[i][j];
                (*cpt)++;
            }
            col++;
            j++;
        }
        lig++;
        i++;
        col = col - j;
    }
    return (1);
}

int     is_free_and_place(char **res, char **tetri, int lig, int col)
{
    int i;
    int cpt;
    char **tab;

    tab = ft_2tabcpy(res);
    cpt = 0;
    if (!is_free(tab, lig, col, tetri, &cpt))
        return (0);
    if (cpt != 4)
        return (0);
    i = 0;
    while (res[i])
    {
        strcpy(res[i], tab[i]);
        i++;
    }
    return (1);
}

int     compute(char **res, char ***tetris, int nbtetri)                /* 37 lignes */
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
    int     i;

    i = 0;
    nbtetri = siz;
    siz = 2;
	while (siz * siz < (nbtetri * 4))
		siz++;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);
    while (!compute(res, tetris, nbtetri))                          /* si ! reset de res */
	{
		siz++;
		ft_2tabdel(res, siz);
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }
    while (res[i])
        ft_putendl(res[i++]);
    return (1);
}
