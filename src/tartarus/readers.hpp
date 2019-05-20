#pragma once
#include <nlohmann/json.hpp>

#include <string>
#include <fstream>

#include <stdexcept>

namespace tartarus
{
namespace readers
{
    /// The function reads the content of a file and returns it as a vector of uint8_t values
    /// @param path is a std::string representing the path to the file
    /// @return a std::vector<uint8_t> with the data from the file. If an error occures and empty vector is returned     
    inline std::vector<uint8_t> vector_disk_reader(const std::string& path)
    {
        std::ifstream instream(path, std::ios::in | std::ios::binary);
        std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());
        return data;
    }

    // TODO: DO NOTE DELETE MUST BE FIXED as it is quicker than above 
    /// The function reads the content of a file and returns it as a vector of uint8_t values
    /// @param src is a std::string representing the path to the file
    /// @param file_size size_t represent the size of the file in bytes
    /// @return a std::vector<uint8_t> with the data from the file. If an error occures and empty vector is returned 
    // std::vector<uint8_t> disk_storage::read_vector_from_disk(std::string src, size_t file_size)
    // {

    //     FILE* fptr;
    //     if ((fptr = fopen(src.c_str(), "rb")) == NULL)
    //     {
    //         std::cout << "File not found" << std::endl;
    //         // m_log.error("File not found");
    //         return {};
    //     }

    //     uint8_t* cdata = (uint8_t*) malloc(file_size * sizeof(uint8_t));

    //     if(fread(cdata, sizeof(uint8_t), file_size, fptr) != file_size)
    //     {
    //         //m_log.error("Could not read file");
    //         std::cout << "Error reading file" << std::endl;            
    //         return {};
    //     }

    //     std::vector<uint8_t> data(cdata, cdata + file_size);

    //     return data;
    
    // }
    inline nlohmann::json json_reader(const std::string& file_path)
    {
        nlohmann::json json_data;

        std::ifstream input(file_path);

        if(input.fail())
        {
            throw std::runtime_error("Unable to open file " + file_path);
        }
    
        input >> json_data;
        return json_data;
    }

    inline nlohmann::json bjson_reader(std::string path)
    {
        std::vector<uint8_t> bdata = vector_disk_reader(path);
        return nlohmann::json::from_bson(bdata);
    }

    inline nlohmann::json ubjson_reader(std::string path)
    {
        std::vector<uint8_t> ubjson_data = vector_disk_reader(path);
        return nlohmann::json::from_ubjson(ubjson_data);
    }        

    inline nlohmann::json cbor_reader(std::string path)
    {
        std::vector<uint8_t> cbor_data = vector_disk_reader(path);
        return nlohmann::json::from_cbor(cbor_data);
    }

    inline nlohmann::json msgpack_reader(std::string path)
    {
        std::vector<uint8_t> msgpack_data = vector_disk_reader(path);
        return nlohmann::json::from_msgpack(msgpack_data);
    }
    
}
}
