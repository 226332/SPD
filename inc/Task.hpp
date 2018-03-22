#pragma once
#include "StandardIncludes.hpp"

struct Task {
    size_t r;
    size_t p;
    size_t q;
};

using Tasks = std::vector<Task>;

Tasks readTaskFile(const std::string & fileName);

