#include "fillit.h"


char        ***ft_tab2tabnew(int nbtab, int nbl, int nbc)
{
    char    ***tab;
	int     i;

	i = 0;
	if (!(tab = (char ***)ft_memalloc(sizeof(char **) * (nbtab + 1))))
        return (0);
	while (i < nbtab)
	 {
        tab[i] = ft_2tabnew(nbl, nbc);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char        **ft_2tabnew(int nbl, int nbc)
{
    char    **tab;
	int     i;

    i = 0;
    if (!nbl || !nbc)
        return (NULL);
    if (!(tab = (char **)malloc(sizeof(char *) * (nbl + 1))))
         return (0);
    while(i < nbl)
    {
        tab[i] = (ft_strnew(nbc + 1));
        i++;
    }
    tab[i] = '\0';
	return (tab);
}

char        **ft_2tabcpy(char **tab)
{
    int     i;
    char    **tmp;

    tmp = ft_2tabnew(4, 4);
    i = 0;
    while (i < 4)
    {
        strcpy(tmp[i], tab[i]);
        i++;
    }
    return (tmp);
}
