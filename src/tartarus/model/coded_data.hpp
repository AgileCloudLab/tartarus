#ifndef TARTARUS_MODEL_CODE_DATA_H
#define TARTARUS_MODEL_CODE_DATA_H

#include "coded_pair.hpp"

#include <nlohmann/json.hpp>

#include <vector>
#include <cstdint>
#include <vector>

namespace tartarus
{
namespace model
{

struct coded_data {
    
    const uint64_t file_id;
    const uint32_t file_size;
    
    const std::string file_name;
    const std::string mime_type;
        
    const nlohmann::json coding_configuration; 
    std::vector<coded_pair> pairs;
};
}
}

#endif /* TARTARUS_MODEL_CODE_DATA_H */ 
