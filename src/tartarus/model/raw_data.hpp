#ifndef TARTARUS_MODEL_RAW_DATA_H
#define TARTARUS_MODEL_RAW_DATA_H

#include <cstdint>
#include <string>
#include <vector>

namespace tartarus
{
namespace model
{
struct raw_data {
    const uint64_t file_id;
    const uint32_t file_size;
    
    const std::string file_name;
    const std::string mime_type;
    
    std::vector<uint8_t> data;

};
}
}
#endif /* TARTARUS_MODEL_RAW_DATA_H */
