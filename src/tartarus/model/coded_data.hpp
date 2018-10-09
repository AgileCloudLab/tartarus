#pragma once

#include <vector>
#include <cstdint>

namespace tartarus
{
namespace model
{
struct coded_data {
    uint64_t file_id;
    std::vector<uint8_t> pivot;
    std::vector<uint8_t> deviation;
};
}
}
