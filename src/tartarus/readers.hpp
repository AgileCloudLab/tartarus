#ifndef TARTARUS_READERS_H
#define TARTARUS_READERS_H

#include <nlohmann/json.hpp>

#include <string>

namespace tartarus
{
namespace readers
{
    /// The function reads the content of a file and returns it as a vector of uint8_t values
    /// If file cannot be read, run time exceptions are thrown.
    /// @param path is a std::string representing the path to the file
    /// @return a std::vector<uint8_t> with the data from the file. If an error occures and empty vector is returned 
    std::vector<uint8_t> vector_disk_reader(const std::string& path);

    /// Reads a json file on disk and returns the its json object
    /// @param path of the json file on disk
    /// @return a nlohmann::json object
    nlohmann::json json_reader(const std::string& path);

    /// Reads a BSON file on disk and converts the content to JSON
    /// @param path of the BSON file on disk
    /// @return a nlohmann::json object
    nlohmann::json bjson_reader(const std::string& path);

    /// Reads a UBSON file on disk and converts the content to JSON
    /// @param path of the UBSON file on disk
    /// @return a nlohmann::json object    
    nlohmann::json ubjson_reader(const std::string& path);

    /// Reads a CBOR file on disk and converts the content to JSON
    /// @param path of the CBOR file on disk
    /// @return a nlohmann::json object    
    nlohmann::json cbor_reader(const std::string& path);

    /// Reads a MSG_PACK file on disk and converts the content to JSON
    /// @param path of the MSG_PACK file on disk
    /// @return a nlohmann::json object    
    nlohmann::json msgpack_reader(const std::string& path);
    
}
}
#endif /*TARTARUS_READERS_H*/
