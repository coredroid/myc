#include <stdio.h>
#include <limits.h>
#include <unistd.h>
main()
{
	char path[PATH_MAX];
	getcwd(path,PATH_MAX);
	printf("hello world~!\n%s\n",path);
}
