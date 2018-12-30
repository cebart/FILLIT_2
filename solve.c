#include "fillit.h"

            /* in progress */

char     **is_free_and_place(char **res, char **tetri, int lig, int col)
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

    i = 0;                              /* debug */
	while (res[i] != NULL)
	{
        ft_putendl(res[i]);
        i++;
        if (cpt != 4)
            ft_putendl("KO cpt");
	}                                   /* fin debug */

    if (cpt != 4)
        return (NULL);
    return (res);
}

char    **compute(char **res, char ***tetris)               /* alterner ligne puis colonne */
{
    int     t;
    int     i;
    int     j;
    char    **tmp;

    i = 0;
    j = 0;
    t = 0;

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
                    if ((tmp = is_free_and_place(tmp, tetris[t], i, j)))
                    {
                        ft_putendl("Placed");               /* debug */
                        t++;
                        break ;
                    }
                    else
                        return (NULL);
                    t++;
                }
            }
            i++;
        }
        j++;
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

    res = ft_2tabnew(siz, siz);
    res = ft_2tabfill(res, '.', siz);

    while (!(compute(res, tetris)))
	{
		siz++;
		ft_2tabdel(res, siz);
		res = ft_2tabnew(siz, siz);
		res = ft_2tabfill(res, '.', siz);
    }


 /*     int i = 0
       	while (tmp)                                  debug
	{
        ft_putendl(tmp[i]);
        i++;
	}                                            fin debug */

    return (1);
}
