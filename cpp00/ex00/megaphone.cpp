#include <iostream>

void ft_uper(char *a)
{
    int i = 0;
    while(a[i])
    {
        if(a[i] >= 97 && a[i] <= 122)
            a[i] = a[i] - 32;
        std::cout << a[i];
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for(int i = 1; i < argc; i++)
        ft_uper(argv[i]);
    std::cout << std::endl;
    return 0;
}