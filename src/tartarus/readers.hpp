#ifndef TARTARUS_READERS_H
#define TARTARUS_READERS_H

#include <nlohmann/json.hpp>

#include <string>

namespace tartarus
{
namespace readers
{
    /// The function reads the content of a file and returns it as a vector of uint8_t values
    /// @param path is a std::string representing the path to the file
    /// @return a std::vector<uint8_t> with the data from the file. If an error occures and empty vector is returned     
    std::vector<uint8_t> vector_disk_reader(const std::string& path);
    
    nlohmann::json json_reader(const std::string& file_path);

    nlohmann::json bjson_reader(std::string path);

    nlohmann::json ubjson_reader(std::string path);
        
    nlohmann::json cbor_reader(std::string path);
    
    nlohmann::json msgpack_reader(std::string path);
    
}
}
#endif /*TARTARUS_READERS_H*/
