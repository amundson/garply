#include "garply.h"
#include "garply_version.h"
#include <iostream>

const int Garply::version_major = garply_version_major;
const int Garply::version_minor = garply_version_minor;

Garply::Garply() {}

int
Garply::get_version() const
{
    return 10 * version_major + version_minor;
}

int
Garply::garplinate() const
{
    std::cout << "Garply::garplinate version " << get_version() << " invoked\n";
    return get_version();
}
