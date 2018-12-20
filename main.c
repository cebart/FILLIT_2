#include "fillit.h"



int     	main(int argc, char **argv)
{
	int     fd;

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
	check_file(fd);
	close(fd);
	return (0);
}
