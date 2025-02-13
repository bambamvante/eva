// #include "get_next_line.h"

// // int main()
// // {
// // 	int fd = open("get_next_line.h", O_RDONLY);
// // 	char *line = get_next_line(fd);
// // 	while (line != NULL)
// // 	{
// // 		printf("%s", line);
// // 		line = get_next_line(fd);
// // 	}
// // 	close(fd);
// // }

// // int main()
// // {
// // 	int fd1 = open("main.c", O_RDONLY);
// // 	int fd2 = open("get_next_line.h", O_RDONLY);
// // 	char *line1 = get_next_line(fd1);
// // 	char *line2 = get_next_line(fd2);
// // 	while (line1 != NULL || line2 != NULL)
// // 	{
// // 		printf("%s", line1);
// // 		printf("%s", line2);
// // 		free(line1);
// // 		free(line2);
// // 		line1 = get_next_line(fd1);
// // 		line2 = get_next_line(fd2);
// // 	}
// // 	close(fd1);
// // 	close(fd2);
// // }