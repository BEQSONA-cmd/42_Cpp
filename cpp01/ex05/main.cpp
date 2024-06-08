#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("unknown");
    harl.complain("debug");
    harl.complain("error");
    harl.complain("warning");
    harl.complain("info");

    return (0);
}
