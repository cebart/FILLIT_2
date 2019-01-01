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
        if (!(tetris = get_tetri(fd, (nbtetris) / 5)))
        {
            ft_putendl_fd("error", 2);
            return (0);
        }
    }
    else
        {
            ft_putendl_fd("error", 2);
            return (0);
        }
    solve((nbtetris / 5), tetris);
	return (0);
}
