#include <iostream>
#include "garply.h"

namespace {
const int garply_version = 1;
}

const int Garply::version = garply_version;

Garply::Garply()
{
}

int
Garply::garplinator() const
{
    std::cout << "Garply::garplinator version " << version << " invoked\n";
    return version;
}
