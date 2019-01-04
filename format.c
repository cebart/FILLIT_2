#include "fillit.h"

void    align_line(char **tetri)
{
    int     i;
    char    *tmp;

    tmp = ft_strnew(4);
    tmp = ft_strcpy(tmp, tetri[0]);
    i = 0;
    while (i < 3)
    {
        tetri[i] = ft_strcpy(tetri[i], tetri[i+1]);
        i++;
    }
    tetri[3] = ft_strcpy(tetri[3], tmp);
}

void    align_col(char **tetri)
{
    int i;
    int j;

    j = 0;
    while (j < 3)
    {
        i = 0;
        while (tetri[i])
        {
            tetri[i][j] = tetri[i][j+1];
            i++;
        }
        j++;
    }
    i = 0;
    j = 3;
    while (tetri[i])
    {
        tetri[i][j] = '.';
        i++;
    }
}

void    test_line(char **tetri)
{
    int i;
    int j;
    int bool_bloc;

    bool_bloc = 0;
    while (bool_bloc != 1)
    {
        i = 0;
        j = 0;
        while (tetri[i][j])
        {
            if (tetri[i][j] == '#')
            {
                bool_bloc = 1;
                break ;
            }
            j++;
        }
        if (bool_bloc == 0)
            align_line(tetri);
        i++;
    }
}

void    test_col(char **tetri)
{
    int i;
    int j;
    int bool_bloc;

    bool_bloc = 0;
    while (bool_bloc != 1)
    {
        i = 0;
        j = 0;
        while (tetri[i])
        {
            if (tetri[i][j] == '#')
            {
                bool_bloc = 1;
                break ;
            }
            i++;
        }
        if (bool_bloc == 0)
            align_col(tetri);
        j++;
    }
}

char    **format_tetri(char **tetri, int c)
{
    int     i;
    int     j;
    char    bloc;

    bloc = 'A';
    i = 0;
    if (c > 25)
        return (NULL);
    test_line(tetri);
    test_col(tetri);
    while ( i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (tetri[i][j] == '#')
                tetri[i][j] = bloc + c;
            j++;
        }
        i++;
    }
    return (tetri);
}
