#include "fillit.h"

            /* in progress */

char     **is_free_and_place(char **res, char **tetri, int lig, int col)
{
    int i;
    int j;

    i = 0;
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
                res[lig][col] = tetri[i][j];
            col++;
            j++;
        }
        lig++;
        i++;
    }
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
                        ft_putendl("Placed");                           /* debug */
                        break ;
                    }
                    else
                        ft_putendl("KO");               /* debug a remplacer par return (NULL) */
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



int     solve(int size, char ***tetris)
{
    char    **res;

    res = ft_2tabnew(size, size);
    res = ft_2tabfill(res, '.', size);
    compute(res, tetris);

 /*   while (!(compute(res, tetris)))
	{
		size++;
		ft_2tabdel(res, size);
		res = ft_2tabnew(size, size);
		res = ft_2tabfill(res, '.', size);
    } */


 /*     int i = 0
       	while (tmp)                                  debug
	{
        ft_putendl(tmp[i]);
        i++;
	}                                            fin debug */

    return (1);
}
