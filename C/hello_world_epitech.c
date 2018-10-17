/*
 * Nathan Agez: https://github.com/NastyZ98
 * Tek2 2018
 */

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = -1;

    while (str[++i]) {
        my_putchar(str[i]);
    }
}

void my_putstr_wptr(char *str)
{
    while (*str) {
        my_putchar(*str++);
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    my_putstr("Hello World\n");
    my_putstr_wptr("Hello World\n");
    return (0);
}