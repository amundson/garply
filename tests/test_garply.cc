#include <stdexcept>

#include "garply/garply.h"

bool
test_construct()
{
    Garply garply;
    return true;
}

bool
test_garplinator()
{
    Garply garply;
    return (garply.garplinator() == Garply::version);
}

int
main(int argc, char* argv[])
{
    if(!test_construct()) {
        throw std::runtime_error("test_construct failed");
    }
    if(!test_garplinator()) {
        throw std::runtime_error("test_garplinator failed");
    }
}
