#pragma once

#include "coded_pair.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <cstdint>

namespace tartarus
{
namespace model
{

struct coded_data {
    const uint64_t file_id;
    const nlohmann::json coding_configuration; 
    std::vector<coded_pair> pairs;
};
}
}
