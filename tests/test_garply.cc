#include <stdexcept>

#include "garply/garply.h"

namespace {
bool
test_construct()
{
    Garply garply;
    return true;
}

bool
test_garplinate()
{
    Garply garply;
    return (garply.garplinate() == garply.get_version());
}
} // namespace

int
main(int argc, char* argv[])
{
    if (!test_construct()) {
        throw std::runtime_error("test_construct failed");
    }
    if (!test_garplinate()) {
        throw std::runtime_error("test_garplinate failed");
    }

    return 0;
}
