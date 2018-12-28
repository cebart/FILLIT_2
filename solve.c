#include "fillit.h"

char    **compute(char **res, char ***tetris)
{

    return (res);
}



int     solve(int size, char ***tetris)
{
    char    **res;
    int     i = 0;

    res = ft_2tabnew(size, size);
    res = ft_2tabfill(res, '.', size);
    while (!(compute(res, tetris)))
	{
		size++;
		ft_2tabdel(res, size);
		res = ft_2tabfill(res, '.', size);
    }



	while (res)                                 /* debug */
	{
        ft_putendl(res[i]);
        i++;
	}                                           /* fin debug */
    return (1);
}
