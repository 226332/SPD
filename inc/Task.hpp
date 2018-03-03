#pragma once
#include "StandardIncludes.hpp"

struct Task {
    unsigned int r;
    unsigned int p;
    unsigned int q;
};

using Tasks = std::vector<Task>;

Tasks readTaskFile(const std::string & fileName);

