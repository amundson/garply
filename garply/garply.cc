#include <iostream>
#include "garply.h"

namespace {
#include "garply_version.h"
}

const int Garply::version_major = garply_version_major;
const int Garply::version_minor = garply_version_minor;

Garply::Garply()
{
}

int
Garply::get_version() const
{
    return 10 * version_major + version_minor;
}

int
Garply::garplinator() const
{
    std::cout << "Garply::garplinator version " << get_version()
              << " invoked\n";
    return get_version();
}
