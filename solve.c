#include "fillit.h"

char    **compute(char **res, char ***tetris)
{
    int     t;
    int     l;
    int     c;
    char    **tmp;

    t = 0;
    l = 0;
    c = 0;
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
