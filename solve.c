#include "fillit.h"

int solve(int nbt)
{
    char    **res;
    int     i = 0;

    res = ft_2tabfill(res, '.', nbt);





	while (res)                                 /* debug */
	{
        ft_putendl(res[i]);
        i++;
	}                                           /* fin debug */
	// ft_2tabdel(res, nbt);

    return (1);
}
