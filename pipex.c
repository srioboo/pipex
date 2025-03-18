#include "pipex.h"

int	main(int argc, char **argv)
{
	int	params;

	params = 1;
	if (argc < 5)
		printf("Not enought params!");
	else
	{
		while (params < (argc - 1))
		{
			printf("%d %s", params, argv[params]);
			params++;
		}
	}

	return (0);
}

