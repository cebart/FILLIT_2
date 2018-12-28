#include "fillit.h"

int     is_free(char **res, char **tetri)  /* alterner 0-0 0-1 1-0 1-1... d'abord colle a haut-gauche */
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (res[i])
    {
        /* ... */
    }

    return (1);
}

char    **compute(char **res, char ***tetris)
{
    int     t;
    int     l;
    int     c;
    char    **tmp;

    t = 0;
    l = 0;
    c = 0;
    while (tetris[t])
    {

    }
    tmp = ft_2tabcpy(res);





    return (res);
}



int     solve(int size, char ***tetris)
{
    char    **res;

    res = ft_2tabnew(size, size);
    res = ft_2tabfill(res, '.', size);

    while (!(compute(res, tetris)))
	{
		size++;
		ft_2tabdel(res, size);
		res = ft_2tabnew(size, size);
		res = ft_2tabfill(res, '.', size);
    }


 /*     int i = 0
       	while (tmp)                                  debug
	{
        ft_putendl(tmp[i]);
        i++;
	}                                            fin debug */

    return (1);
}
