#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char *get_content(const char *filename)
{
    printf("%s\n", filename);
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        printf("Problem opening file\n");
        exit(84);
    }
    struct stat s;
    if (stat(filename, &s) == -1) {
        printf("Failed stating file\n");
        exit(84);
    }
    char *ret = malloc(s.st_size + 1);
    if (read(fd, ret, s.st_size) == -1) {
        printf("Failed reading file\n");
        exit(84);
    }
    return (ret);
}

int translate(const char *str)
{
    int ret = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        switch (str[i]) {
            case ('>'): printf("Ook. Ook? "); break;
            case ('<'): printf("Ook? Ook. "); break;
            case ('+'): printf("Ook. Ook. "); break;
            case ('-'): printf("Ook! Ook! "); break;
            case ('.'): printf("Ook! Ook. "); break;
            case ('['): printf("Ook! Ook? "); break;
            case (']'): printf("Ook? Ook! "); break;
            case ('\n'): printf("\n"); break;
            default:
                printf("Invalid '%c' ", str[i]);
                ret++;
                break;
        }
    }
    return (ret);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Wrong arguments : USAGE\n\t./btoo file");
        return (84);
    }
    char *str = get_content(av[1]);
    return (translate(str));
}
