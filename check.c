#include "fillit.h"

int     check_format(const int fd)
{
    int     bool_line;                          /* 1 pour line non vide sinon 0 -> test si 2 saut de ligne */
    int     cpt;                                /* compteur pour verif si 4 ligne avant ligne vide ( ni plus ni moins ) */
    char    *line;
    int     i;
    int     j;                                     /* test si nb de # > 4 ou < 4 */

    bool_line = 0;
    cpt = 0;
    line = ft_strnew(BUFF_SIZE);
    j = 0;
    while (get_next_line(fd, &line) == 1)
    {
        i = 0;
        if (ft_strlen(line))                                /* ligne "pleine" */
        {
            bool_line = 1;
            cpt++;
            if (cpt > 4)
                return (0);
            if (ft_strlen(line) != 4)
                return (0);
            while (i < 4)
            {
                if (line[i] != '.' && line[i] != '#')
                    return (0);
                if (line[i] == '#')
                    j++;
                if (j > 4)
                    return (0);
                i++;
            }
        }
        else                                                    /* ligne vide = saut de ligne */
        {
            if (!bool_line)
                return (0);
            bool_line = 0;
            if ( j != 4)
                return (0);
            j = 0;
            if (cpt != 4)
                return (0);
            cpt = 0;
        }
    }
    if (!bool_line)                                    /* test si saut de ligne juste avant la fin de fichier */
        return (0);
    return (1);
}

int     check_file(const int fd)
{
    if (check_format(fd))                                       /*  pour debug */
        ft_putstr("OK1");
    else
        ft_putstr("KO1");

    return (1);
}
