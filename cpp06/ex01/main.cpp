#include "Serializer.hpp"


void init_data(Data &data)
{
    data.str = "Hello, World!";
    data.num = 42;
}


int main(void)
{
    Data data;

    init_data(data);

    uintptr_t raw = Serializer::serialize(&data);
    Data *new_data = Serializer::deserialize(raw);

    std::cout << "new_data.str: " << new_data->str << std::endl;
    std::cout << "new_data.num: " << new_data->num << std::endl;

    return 0;
}