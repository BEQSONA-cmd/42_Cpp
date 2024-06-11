#include "Point.hpp"

void draw_map(Point a, Point b, Point c, Point point, int color)
{
    float _a[2] = {a.getX(), a.getY()};
    float _b[2] = {b.getX(), b.getY()};
    float _c[2] = {c.getX(), c.getY()};
    float _point[2] = {point.getX(), point.getY()};

    int j = 0;
    int i = 0;
    int x = -15;
    int y = 15;
    while(i < 30)
    {
        j = 0;
        x = -15;
        while(j < 30)
        {
            if(_point[0] == x && _point[1] == y)
            {
                if (color == 1)
                    std::cout << BLUE << "*" << RESET;
                else
                    std::cout << RED << "*" << RESET;
            }
            else if(_a[0] == x && _a[1] == y)
                std::cout << YELLOW << "*" << RESET;
            else if(_b[0] == x && _b[1] == y)
                std::cout << YELLOW << "*" << RESET;
            else if(_c[0] == x && _c[1] == y)
                std::cout << YELLOW << "*" << RESET;
            else if (x == 0 && y == 0)
                std::cout << "+";
            else if (x == 0)
                std::cout << "|";
            else if (y == 0)
                std::cout << "-";
            else 
                std::cout << ".";
            j++;
            x++;
        }
        std::cout << std::endl;
        i++;
        y--;
    }
}

// Formula of : area = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2

float triangle_area(float a[2], float b[2], float c[2])
{
    float area = std::abs((a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1])) / 2);
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float int_a[2] = {a.getX(), a.getY()};
    float int_b[2] = {b.getX(), b.getY()};
    float int_c[2] = {c.getX(), c.getY()};
    float int_point[2] = {point.getX(), point.getY()};

    float abc_area = triangle_area(int_a, int_b, int_c);
    float pbc_area = triangle_area(int_point, int_b, int_c);
    float pac_area = triangle_area(int_a, int_point, int_c);
    float pab_area = triangle_area(int_a, int_b, int_point);
    
    if (abc_area == pbc_area + pac_area + pab_area)
    {
        draw_map(a, b, c, point, 1);
        return true;
    }
    draw_map(a, b, c, point, 0);
    return false;
}
