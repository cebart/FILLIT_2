#include "fillit.h"



int     	main(int argc, char **argv)
{
	int     fd;
    int     nbtetris;

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
        if(!(get_tetri(fd, (nbtetris) / 5)))                            /* if pour debug */
            ft_putendl("KO");
    }
    else
        ft_putendl("KO check");
	return (0);
}
