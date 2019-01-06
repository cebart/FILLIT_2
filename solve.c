#include "fillit.h"

void    del_last_tetri(int t, char ***tetris, char **res)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    j = 0;
    while (tetris[t][0][j])
    {
        if (tetris[t][0][j] != '.')
            c = tetris[t][0][j];
        j++;
    }
    while (res[i])
    {
        j = 0;
        while (res[i][j])
        {
            if (res[i][j] == c)
                res[i][j] = '.';
            j++;
        }
        i++;
    }
}

int    compute_2(char **res, char ***tetris, int t)
{
    int     i;
    int     j;

    i = 0;
    if (!tetris[t])
        return (1);
    while (res[i])
    {
        j = 0;
        while (res[i][j])
        {
            if (is_free_and_place(res, tetris[t], i, j))
            {
                if (compute_2(res, tetris, t+1))
                    return (1);
                else
                    del_last_tetri(t, tetris, res);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int     solve(int siz, char ***tetris)
{
    int     i;
    int     t;
    char    **res;

    t = 0;
    i = 0;
    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);
    if (compute_2(res, tetris, t))
    {
        while (res[i])
            ft_putendl(res[i++]);
        ft_2tabdel(res, siz);
        return (1);
    }
    ft_2tabdel(res, siz);
    return (solve(siz + 1, tetris));                           /*  relancer la fonction avec t + 1 pour commencer par un autre tetri  */
}
