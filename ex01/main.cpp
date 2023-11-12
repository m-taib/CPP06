#include "Serializer.hpp"
#include <stdio.h>

int main()
{
    Data data = {1, 2, 'a', 1};
    printf("%p\n",&data);
    Data *ptr = Serializer::deserialize(Serializer::serialize(&data));
    printf("%p\n",ptr);
    return 0;
}
