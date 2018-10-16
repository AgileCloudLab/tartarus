#pragma once

#include <vector>
#include <cstdint>

namespace tartarus
{
namespace model
{
struct raw_data {
    const uint64_t file_id;
    std::vector<uint8_t> data;
};
}
}
