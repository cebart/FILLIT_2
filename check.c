#include "fillit.h"
#include "get_next_line.h"

/* GNL tout le fichier
 str = concat des 5 1er lignes puis CHECK (test si le retour de GNL fait bien strlen() == 3
 boucle sur les 5 lignes suivante... */

 /* CHECK : boucle sur les 4 premiers char de str & test si '.' ou '#'
 pareil pour les suivants
 si ok test si les 2 derniers sont '\n' et '\0' */

 /* /!\ GNL et '\n'  -> add compteur ( 1 tetri = 5 lignes )  || check GNL return ? si ligne vide == line vide ? */

/*

char    *str;
char    *line;
while (GNL)
    {
            i = 0;
            while (i < 4)
            {
                GNL + concat (str + line)
            }
            test pour i == 4 si GNL retourne chaine vide

            CHECK str
            {
            }
            ft_strdel(str);
    }
*/
int     check_format(const int fd)
{
    int     bool_line;                          /* 1 pour line non vide sinon 0 -> test si 2 saut de ligne */
    int     cpt;                                /* compteur pour verif si 4 ligne avant ligne vide ( ni plus ni moins ) */
    char    *line;
    int     i;

    cpt = 0;
    bool_line = 0;
    while (get_next_line(fd, &line) == 1)
    {
        i = 0;
        if (ft_strlen(line))
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
                i++;
            }
        }
        else
        {
            if (!bool_line)
                return (0);
            bool_line = 0;
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
    if (check_format(fd))
        ft_putstr("OK1");
    else
        ft_putstr("KO1");

    return (1);
}
