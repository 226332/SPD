#pragma once
#include "StandardIncludes.hpp"

struct Task {
    long r;
    long p;
    long q;
};

using Tasks = std::vector<Task>;

Tasks readTaskFile(const std::string & fileName);

