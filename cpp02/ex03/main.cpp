#include "Point.hpp"

int main(int ac, char **av)
{
    if(ac != 3)
    {
        std::cerr << RED << "usage: ./bsp x y" << RESET << std::endl;
        return(1);
    }
    // first triangle
    // Point a(1, 1);
    // Point b(4, 8);
    // Point c(10, 3);
    // Point point(5, 4);

    // second triangle
    // Point a(-3.0f, -3.0f);
    // Point b(0.0f, 3.0f);
    // Point c(3.0f, -3.0f);
    // Point point(0.0f, 0.0f);

    // third triangle
    // Point a(7 , -7);
    // Point b(-7, 7);
    // Point c(7, 7);
    // Point point(-1, -1);

    Point a(1, 1);
    Point b(4, 8);
    Point c(10, 3);
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    Point point(x, y);

    if(bsp(a, b, c, point))
        std::cout << BLUE << "[Point is inside the triangle]" << RESET << std::endl;
    else
        std::cout << RED << "[Point is outside the triangle]" << RESET << std::endl;
    return(0);
}
