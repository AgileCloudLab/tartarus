#include "readers.hpp"

#include <fstream>

#include <filesystem>

#include <stdexcept>


namespace tartarus
{
namespace readers
{

    std::vector<uint8_t> vector_disk_reader(const std::string& path)
    {
        FILE* fptr;
        if ((fptr = fopen(path.c_str(), "rb")) == NULL)
        {
            throw std::runtime_error("Could not open the file");
        }

        // File size in bytes
        uint32_t file_size = std::filesystem::file_size(path);

        std::vector<uint8_t> data(file_size);

        if (fread(data.data(), sizeof(uint8_t), file_size, fptr) != file_size)
        {
            throw std::runtime_error("could not read the file: " + path);
        }

	fclose(fptr);
	
        return data;
    }    

    nlohmann::json json_reader(const std::string& path)
    {
        nlohmann::json json_data;

        std::ifstream input(path);

        if(input.fail())
        {
            throw std::runtime_error("Unable to open file " + path);
        }
    
        input >> json_data;
        return json_data;
    }

    nlohmann::json bjson_reader(const std::string& path)
    {
        std::vector<uint8_t> bdata = vector_disk_reader(path);
        return nlohmann::json::from_bson(bdata);
    }

    nlohmann::json ubjson_reader(const std::string& path)
    {
        std::vector<uint8_t> ubjson_data = vector_disk_reader(path);
        return nlohmann::json::from_ubjson(ubjson_data);
    }        

    nlohmann::json cbor_reader(const std::string& path)
    {
        std::vector<uint8_t> cbor_data = vector_disk_reader(path);
        return nlohmann::json::from_cbor(cbor_data);
    }

    nlohmann::json msgpack_reader(const std::string& path)
    {
        std::vector<uint8_t> msgpack_data = vector_disk_reader(path);
        return nlohmann::json::from_msgpack(msgpack_data);
    }    
}
}
