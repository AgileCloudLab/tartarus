#pragma once

#include <vector>
#include <cstdint>

namespace tartarus
{
namespace model
{
struct coded_pair {
    const std::vector<uint8_t> pivot;
    const std::vector<uint8_t> deviation;
};

struct coded_data {
    const uint64_t file_id;
    std::vector<coded_pair> pairs;
};
}
}
