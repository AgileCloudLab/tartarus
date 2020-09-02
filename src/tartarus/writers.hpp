#ifndef TARTARUS_WRITERS_H
#define TARTARUS_WRITERS_H

#include <nlohmann/json.hpp>

#include <string>
#include <cstdint>
#include <vector>

#include <fstream>

namespace tartarus
{
namespace writers
{
    bool vector_disk_writer(const std::string& path, const std::vector<uint8_t>& data);
    
    /// The function writes a vector of uint8_t to the destination provided by path. Note that the
    /// path must contain the file name and if needed file extension.
    /// @param path is std::string representation of the path to the destination file where the data will be written
    /// @param data is a std::vector<uint8_t> which keeps the data which will be written to disk
    /// @param sync forces sync of file 
    /// @return true if success
    bool vector_disk_writer(const std::string& path, const std::vector<uint8_t>& data, bool sync);
    
    /// The function writes a piece of json to the file path provided
    /// @param path is a string representation of the system path to where the file is written
    /// @param data is a json object 
    void json_writer(const std::string& path, const nlohmann::json& data);

    /// The function converts a JSON object to BSON and writes it to a file on disk
    /// @param path is a string representation of the system path to where the file is written
    /// @param data is a json object     
    void bjson_writer(const std::string& path, const nlohmann::json& data);    

    /// The function converts a JSON object to UBSON and writes it to a file on disk
    /// @param path is a string representation of the system path to where the file is written
    /// @param data is a json object         
    void ubjson_writer(const std::string& path, const nlohmann::json& data);

    /// The function converts a JSON object to CBOR and writes it to a file on disk
    /// @param path is a string representation of the system path to where the file is written
    /// @param data is a json object         
    void cbor_writer(const std::string& path, const nlohmann::json& data);

    /// The function converts a JSON object to MSG_PACK and writes it to a file on disk
    /// @param path is a string representation of the system path to where the file is written
    /// @param data is a json object         
    void msgpack_writer(const std::string& path, const nlohmann::json& data);
}
}

#endif /*TARTARUS_WRITERS_H*/
