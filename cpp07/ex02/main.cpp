#include "Array.hpp"
#define MAX_VAL 750
#include <iostream>
#include <ctime>
#include <cstdlib>

void constructor_test(void)
{
    Array<int> int_arr(3);
    int_arr[0] = 1;
    int_arr[0] = 2;
    
    std::cout << int_arr[0] << std::endl;
    Array<int> nums = int_arr;
    std::cout << nums[0] << std::endl;
    Array<int> test(nums);
    std::cout << test[0] << std::endl;
}

void different_types(void)
{
    Array<int> int_arr(3);
    int_arr[0] = 1;
    int_arr[1] = 2;
    int_arr[2] = 3;
    
    Array<std::string> str_arr(3);
    str_arr[0] = "Hello";
    str_arr[1] = "World";
    str_arr[2] = "!";

    Array<char> char_arr(3);
    char_arr[0] = 'a';
    char_arr[1] = 'b';
    char_arr[2] = 'c';
    
    std::cout << int_arr[0] << " " << int_arr[1] << " " << int_arr[2] << std::endl;
    std::cout << str_arr[0] << " " << str_arr[1] << " " << str_arr[2] << std::endl;
    std::cout << char_arr[0] << " " << char_arr[1] << " " << char_arr[2] << std::endl;
}

void out_of_bounds(void)
{
    Array<int> int_arr(3);
    
    try {
        int_arr[3] = 4;
    } catch(const std::exception& err) {
        std::cerr << err.what() << '\n';
    }
    
    try {
        std::cout << int_arr[3] << std::endl;
    } catch(const std::exception& err) {
        std::cerr << err.what() << '\n';
    }
}

void random_tests(void)
{
    std::cout << GREEN "Negative size test: " RESET << std::endl;
    try {
        Array<int> int_arr(-123123);
    } catch(const std::exception& err) {
        std::cerr << err.what() << '\n';
    }
    std::cout << GREEN "Too large size test: " RESET << std::endl;
    try {
        Array<int> int_arr(4294967295);
    } catch(const std::exception& err) {
        std::cerr << err.what() << '\n';
    }


    std::cout << GREEN "Empty array test: " RESET << std::endl;
    Array<int> int_arr(0);
    std::cout << int_arr.size() << std::endl;
    
}


template <class Array>

int main()
{
    std::cout << GREEN "Constructor test: " RESET << std::endl;
    constructor_test();

    std::cout << GREEN "Different types test: " RESET << std::endl;
    different_types();

    std::cout << GREEN "Out of bounds test: " RESET << std::endl;
    out_of_bounds();

    std::cout << GREEN "Random tests: " RESET << std::endl;
    random_tests();

    return 0;
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }