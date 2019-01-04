#include "fillit.h"

void    compute_2(char **res, char ***tetris, int t, char *placed)          /* 28 lignes */
{
    int i;
    int j;
    int cpt;

    i = 0;
    j = 0;
    cpt = 0;
    while (res[i] != '\0')
	{
        j = 0;
        while (res[i][j] != '\0')
		{
            if (cpt)
                t = 0;
            while (tetris[t])
            {
                if (placed[t] != '1' && is_free_and_place(res, tetris[t], i, j))
                {
                    placed[t] = '1';
                    cpt = 1;
                    break ;
                }
                t++;
            }
            j++;
        }
        i++;
    }
}

int     test_compute(char *placed, int nbtetri, char **res)
{
    int i;

    i = 0;
    while (placed[i] == '1' && i < nbtetri)
    {
        if (i == nbtetri - 1)
        {
            i = 0;
            while (res[i])
                ft_putendl(res[i++]);
            return (1);
        }
        i++;
    }
    return (0);
}

int     compute(char **res, char ***tetris, int nbtetri, int t, int siz)
{
    int     i;
    char    *placed;
    int     tmp;

    i = 0;
    tmp = t + 1;
    placed = ft_strnew(nbtetri);
    while (i < nbtetri)
        placed[i++] = '0';
    compute_2(res, tetris, t, placed);
    if (test_compute(placed, nbtetri, res))
        return (1);
    if (tmp < nbtetri)
    {
        ft_2tabdel(res, siz);
        res = ft_2tabnew(siz, siz);
        res = ft_2tabfill(res, '.', siz);
        return (compute(res, tetris, nbtetri, tmp, siz));                           /*  relancer la fonction avec t + 1 pour commencer par un autre tetri  */
    }
    return (0);
}

int     solve(int siz, char ***tetris)
{
    char    **res;
    int     nbtetri;

    nbtetri = siz;
    siz = 2;
	while (siz * siz < (nbtetri * 4))
		siz++;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);
    while (!compute(res, tetris, nbtetri, 0, siz))
	{
		siz++;
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }
    return (1);
}
