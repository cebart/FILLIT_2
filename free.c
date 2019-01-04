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
