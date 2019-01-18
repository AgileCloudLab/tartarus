#pragma once

#include <cstdint>
#include <vector> 
namespace tartarus
{
namespace model
{

struct coded_pair {
    const std::vector<uint8_t> pivot;
    const std::vector<uint8_t> deviation;
};
}
}
