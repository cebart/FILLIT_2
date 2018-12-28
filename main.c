#include "fillit.h"



int     	main(int argc, char **argv)
{
	int     fd;
    int     nbtetris;
    char    ***tetris;

    nbtetris = 1;
	if (argc == 1)
	{
		write(2, "fillit: missing file operand.", 29);
			return (1);
	}
	else if (argc > 2)
	{
		 write(2, "Too many arguments.", 19);
			 return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (check_file(fd, &nbtetris))
    {
        close(fd);
        fd = open(argv[1], O_RDONLY);
        tetris = get_tetri(fd, (nbtetris) / 5);
    }
    else
        ft_putendl("KO check");


 /*   int i = 0;                               debug
    int j;
	while (tetris[i] != NULL)
	{
        j = 0;
        while (j < 4)
        {
            ft_putendl(tetris[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
	}                                             fin debug */


    if(!(solve((nbtetris / 5), tetris)));                       /* if = debug */
        ft_putendl("KO_solve");
	return (0);
}
